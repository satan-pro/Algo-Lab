#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int arr[100];
    int top;
};
typedef struct Stack* stack;

int isEmpty(stack s)
{
    if(s->top==-1)
    {
        return 1;
    }
    return 0;
}

void push(stack s, int n)
{
    s->arr[++s->top]=n;
}

int peek(stack s)
{
    if(!isEmpty(s))
    {
        return s->arr[s->top];
    }
}

int pop(stack s)
{
    if(!isEmpty(s))
    {
        return s->arr[s->top--];
    }
    return -1;
}