#include "Stack.h"
#include <stdio.h>
Stack::Stack()
{
    //ctor
    head=0;
}

Stack::~Stack()
{
    //dtor
}
int Stack::pop()
{
    if(!Stack::isEmpty())
        return data[--head];
    else
    {
        printf("the stack is empty");
        return 0;
    }

}
void Stack::push(int d)
{
    if(head<sizeof(data))
        data[head++]=d;
    else
        printf("stack is full");
}
bool Stack::isEmpty()
{
    if(head==0)
        return true;
    else
        return false;
}
