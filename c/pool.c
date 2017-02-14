#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct pool
{
	char *next;
	char *end;
} POOL;

POOL * pool_create( size_t size )
{
	POOL * p = (POOL*)malloc( size + sizeof(POOL) );
	p->next = (char*) &p[1];
	p->end = p->next + size;
	return p;
}

void pool_destory( POOL *p )
{
	free(p);
}

size_t pool_available( POOL *p )
{
	return p->end - p->next;
}

void * pool_alloc( POOL *p, size_t size )
{
	if(pool_available(p) < size) return NULL;
	void *mem = (void*)p->next;
	p->next += size;
	return mem;
}

int main()
{
	POOL *p = pool_create(10);
	void* mem = pool_alloc(p, 2);
	printf("%s\n", (char*)mem);
	return 0;
}

