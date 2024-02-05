#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int n;
void dfs(int* v, int i, int **adj_mat, int n, stack s)
{
    /* push(s, i);
    v[i]=1;
    int curr = pop(s);
    for (int j = 0;  j< n; j++)     
    {
        printf("%d ", curr);
        if(adj_mat[curr][j]==1 && !v[j])
        {
            push(s, j);
        }
    } */
    push(s, i);
    printf("Pushed : %d\n", i);
    v[i]=0;
    while(!isEmpty(s))
    {
        int curr=pop(s);
        printf("Popped : %d\n", curr);
        printf("%d ", curr);
        for(int j=0; j<n; j++)
        {
            if(adj_mat[i][j]==1 && !v[j])
            {
                v[j]=1;
                push(s, j);
                printf("Pushed : %d\n", j);
            }
        }
    }
    
}

int main()
{
    stack s = (stack)malloc(sizeof(struct Stack));
    s->top = -1;

    printf("Enter no of vertices : ");
    scanf("%d", &n);
    int** adj_mat = (int**)malloc(n*sizeof(int*));
    int ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            printf("Is vertex %d connected to vertex %d?(1/0) : ", i, j);
            scanf("%d", &ch);
            if (ch)
            {
                adj_mat[i][j] = 1;
                adj_mat[j][i] = 1;
            }
            else{
                adj_mat[i][j]=0;
                adj_mat[i][j]=0;
            }
        }
    }
    int v[n];
    for(int i=0; i<n; i++)
    {
        v[i]=0;
    }
    for(int i=0; i<n; i++)
    {
        if(v[i]==0)
        {
             dfs(v, i, adj_mat, n, s);
        }
    }
}
       