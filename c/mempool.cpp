#include <stddef.h>
#include <string.h>
#include <string>
#include <iostream>
#include <stdio.h>

struct Block
{
	Block *next_;
	char block[1024];
};


class MemPool
{
public:
	MemPool(size_t poolSize):
	m_poolSize(poolSize),m_freeCount(poolSize), m_freeList(NULL)
	{
		for (size_t i = 0; i < poolSize; i++) {
			Block *tmp = new Block();
			tmp->next_ = this->m_freeList;
			this->m_freeList = tmp;
		}
	}

	~MemPool()
	{
		while (this->m_freeList != 0) {
			Block *tmp = this->m_freeList;
			this->m_freeList = this->m_freeList->next_;
			delete tmp;
		}
			
	}

	void * Alloc(size_t size, bool usepool = true)
	{
		if (size != 1024) return NULL;
		
		Block* tmp;
		if(usepool){
			tmp = this->m_freeList;
			if (tmp != 0) {
				this->m_freeList = this->m_freeList->next_;
				this->m_freeCount --;
			}
		}
		else {
			tmp = new Block();
		}
		return tmp->block;
	}

	void Free(void* ptr)
	{
		if (ptr != 0) {
			Block *tmp = (Block*) ((char*)ptr - sizeof(size_t));
			tmp->next_ = this->m_freeList;
			this->m_freeList = tmp;
			this->m_freeCount ++;
		}
	}

	size_t size()
	{
		return m_freeCount;
	}

private:
	Block * 	m_freeList;
	size_t  m_poolSize;
	size_t 	m_freeCount;
};


class CMemPool
{
private:
    //The purpose of the structure`s definition is that we can operate linkedlist conveniently
    struct _Unit                     //The type of the node of linkedlist.
    {
        struct _Unit *pPrev, *pNext;
    };

    void* m_pMemBlock;                //The address of memory pool.

    //Manage all unit with two linkedlist.
    struct _Unit*    m_pAllocatedMemBlock; //Head pointer to Allocated linkedlist.
    struct _Unit*    m_pFreeMemBlock;      //Head pointer to Free linkedlist.

    unsigned long    m_ulUnitSize; //Memory unit size. There are much unit in memory pool.
    unsigned long    m_ulBlockSize;//Memory pool size. Memory pool is make of memory unit.

public:
    CMemPool(unsigned long lUnitNum = 50, unsigned long lUnitSize = 1024);
    ~CMemPool();
    
    void* Alloc(unsigned long ulSize, bool bUseMemPool = true); //Allocate memory unit
    void Free( void* p );                                   //Free memory unit
};

CMemPool::CMemPool(unsigned long ulUnitNum,unsigned long ulUnitSize) :
    m_pMemBlock(NULL), m_pAllocatedMemBlock(NULL), m_pFreeMemBlock(NULL), 
    m_ulBlockSize(ulUnitNum * (ulUnitSize+sizeof(struct _Unit))), 
    m_ulUnitSize(ulUnitSize)
{    
    m_pMemBlock = malloc(m_ulBlockSize);     //Allocate a memory block.
    
    if(NULL != m_pMemBlock)
    {
        for(unsigned long i=0; i<ulUnitNum; i++)  //Link all mem unit . Create linked list.
        {
            struct _Unit *pCurUnit = (struct _Unit *)( (char *)m_pMemBlock + i*(ulUnitSize+sizeof(struct _Unit)) );
            
            pCurUnit->pPrev = NULL;
            pCurUnit->pNext = m_pFreeMemBlock;    //Insert the new unit at head.
            
            if(NULL != m_pFreeMemBlock)
            {
                m_pFreeMemBlock->pPrev = pCurUnit;
            }
            m_pFreeMemBlock = pCurUnit;
        }
    }    
} 

CMemPool::~CMemPool()
{
    free(m_pMemBlock);
}

void* CMemPool::Alloc(unsigned long ulSize, bool bUseMemPool)
{
    if(    ulSize > m_ulUnitSize || false == bUseMemPool || 
        NULL == m_pMemBlock   || NULL == m_pFreeMemBlock)
    {
        return malloc(ulSize);
    }

    //Now FreeList isn`t empty
    struct _Unit *pCurUnit = m_pFreeMemBlock;
    m_pFreeMemBlock = pCurUnit->pNext;            //Get a unit from free linkedlist.
    if(NULL != m_pFreeMemBlock)
    {
        m_pFreeMemBlock->pPrev = NULL;
    }

    pCurUnit->pNext = m_pAllocatedMemBlock;
    
    if(NULL != m_pAllocatedMemBlock)
    {
        m_pAllocatedMemBlock->pPrev = pCurUnit; 
    }
    m_pAllocatedMemBlock = pCurUnit;

    return (void *)((char *)pCurUnit + sizeof(struct _Unit) );
}

void CMemPool::Free( void* p )
{
    if(m_pMemBlock<p && p<(void *)((char *)m_pMemBlock + m_ulBlockSize) )
    {
        struct _Unit *pCurUnit = (struct _Unit *)((char *)p - sizeof(struct _Unit) );

        m_pAllocatedMemBlock = pCurUnit->pNext;
        if(NULL != m_pAllocatedMemBlock)
        {
            m_pAllocatedMemBlock->pPrev = NULL;
        }

        pCurUnit->pNext = m_pFreeMemBlock;
        if(NULL != m_pFreeMemBlock)
        {
             m_pFreeMemBlock->pPrev = pCurUnit;
        }

        m_pFreeMemBlock = pCurUnit;
    }
    else
    {
        free(p);
    }
}


using namespace std;

int main(int argc, char* argv[])
{
	int n=100;
	int repeat = 100000;
	if(argc<2) return -1;
	int t = atoi(argv[1]);
	char** mlist = new char*[n];

	if(t==1) {
		MemPool pool(n);
		for(int c=0; c<repeat; c++){
			for(int i=0; i<n; i++) {
				mlist[i] = (char*)pool.Alloc(1024, true);
				//sprintf(mlist[i], "abc%d", i);
			}
			for(int i=0; i<n; i++) {
				pool.Free(mlist[i]);
			}
		}
		return 0;
	}
	else if(t==2) {
		MemPool pool(n);
		for(int c=0; c<repeat; c++){
			for(int i=0; i<n; i++) {
				mlist[i] = (char*)pool.Alloc(1024, false);
				//sprintf(mlist[i], "abc%d", i);
			}
			for(int i=0; i<n; i++) {
				free(mlist[i] - sizeof(size_t));
			}
		}
		return 0;
	}
	else if (t==3) {
		CMemPool p2(n, 1024);
		for(int c=0; c<repeat; c++){
			for(int i=0; i<n; i++) {
				mlist[i] = (char*)p2.Alloc(1024, true);
				//sprintf(mlist[i], "abc%d", i);
			}
			for(int i=0; i<n; i++) {
				p2.Free(mlist[i]);
			}
		}
	}
	else if (t==4) {
		CMemPool p2(n, 1024);
		for(int c=0; c<repeat; c++){
			for(int i=0; i<n; i++) {
				mlist[i] = (char*)p2.Alloc(1024, false);
				//sprintf(mlist[i], "abc%d", i);
			}
			for(int i=0; i<n; i++) {
				p2.Free(mlist[i]);
			}
		}
	}
	else {
		return 0;
	}
}
