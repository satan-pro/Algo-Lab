/*Write a program to find GCD using middle school method and analyze its time
efficiency.*/

#include <stdio.h>
#include <stdlib.h>

int opcount=0;

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

stack primeFactors(int n, stack s)
{
    printf("Reached here\n");
    int k=n;
    for(int i=2; i<=k; i++)
    {
        while(n%i==0)
        {
            printf("%d\n",i);
            push(s,i);
            n/=i;
        }
    }
}

int compareValues(stack s1, stack s2, int prod)
{
    while(!isEmpty(s1)&&!isEmpty(s2))
    {
        printf("%d %d\n", s1->top, s2->top);
        int m1 = peek(s1);
        int m2 = peek(s2);
        printf("%d %d\n", m1, m2);
        printf("%d\n", prod);
        if(m1==m2)
        {
            prod*=m1;
            s1->top--;
            s2->top--;
        }
        else if(m1>m2){
            s1->top--;
        }
        else if(m1<m2){
            s2->top--;
        }
    }
    return prod;
}

int main()
{
    int m,n;
    printf("Enter 2 numbers : ");
    scanf("%d %d", &m, &n);

    stack s1 = (stack)malloc(sizeof(struct Stack));
    stack s2 = (stack)malloc(sizeof(struct Stack));
    s1->top=-1;
    s2->top=-1;

    primeFactors(m, s1);
    primeFactors(n, s2);

    int gcd= compareValues(s1,s2,1);

    printf("Value of GCD : %d", gcd);
    return 0;
}