#ifndef STACK_H
#define STACK_H


class Stack
{
    public:
        Stack();
        virtual ~Stack();
        int pop();
        void push(int d);
        bool isEmpty();
    private:
        int head;
        int data[10];
};

#endif // STACK_H
