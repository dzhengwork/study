#include <stdio.h>
#include <string>

using namespace std;

template <class T>
struct Entry {
    T     data;
    Entry*  next;
    Entry(T data) : data(data), next(NULL) {}
};

template <class T>
class Stack {
    private:
        Entry<T>* _head;
    public:
        Stack() {_head = NULL;}
        ~Stack() {if (_head) delete _head; }
        void push(T data);
        void pop();
        T top();
        void print();
};

template <class T>
void Stack<T>::push(T data) {
    if (_head == NULL) _head = new Entry<T>(data);
    else {
        Entry<T>* newhead = new Entry<T>(data);
        newhead->next = _head;
        _head = newhead;
    }
}

template <class T>
void Stack<T>::pop() {
    if (_head) {
        Entry<T>* tbd = _head;
        _head = _head->next;
        delete tbd;
    }
}

template<> 
void Stack<int>::print() {
    Entry<int>* cur = _head;
    while(cur) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    printf("\n");
}

template<> 
void Stack<string>::print() {
    Entry<string>* cur = _head;
    while(cur) {
        printf("%s ", cur->data.c_str());
        cur = cur->next;
    }
    printf("\n");
}

template <>
string Stack<string>::top() {
    if(_head == NULL) return "";
    return _head->data;
}

template <>
int Stack<int>::top() {
    if(_head == NULL) return 0;
    return _head->data;
}

int main()
{
    Stack<int>  iStack;
    Stack<string> sStack;

    iStack.push(10);
    iStack.push(20);
    iStack.push(30);
    iStack.push(40);
    iStack.print();
    printf("-------------top int: %d\n", iStack.top());
    iStack.pop();
    iStack.print();
    iStack.pop();
    iStack.print();
    printf("++++++++++++++++++++\n");

    sStack.push("a");
    sStack.push("b");
    sStack.push("c");
    sStack.push("d");
    sStack.print();
    printf("-------------top string: %s\n", sStack.top().c_str());
    sStack.pop();
    sStack.print();
    sStack.pop();
    sStack.print();
    return 0;
}

