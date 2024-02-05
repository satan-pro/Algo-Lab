#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int n;
    int* arr;
    int top;
};
typedef struct Stack* stack;

stack createStack(int n)
{
    stack s = (stack)malloc(sizeof(struct Stack));
    s->n=n;
    s->arr = (int*)malloc(n*sizeof(int));
    s->top=-1;

    return s;
}

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
}
