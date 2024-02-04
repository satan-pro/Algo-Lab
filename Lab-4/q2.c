#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void dfs(int *v, int *adj_mat[], int n, stack s)
{
    int i = 0;
    do
    {
        if (v[i])
        {
            i = pop(s);
            printf("%d ", i);
        }
        else
        {
            push(s,i);
            v[i] = 1;
            for (int j = 0; j < n; j++)
            {
                int vertex = adj_mat[i][j];
                if (vertex == 1)
                {
                    i = j;
                    break;
                }
            }
        }
    } while (!v[i]);
}
int main()
{
    stack s = (stack)malloc(sizeof(struct Stack));
    s->top = -1;

    int n;
    printf("Enter no of vertices : ");
    scanf("%d", &n);
    int adj_mat[n][n];
    int ch;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
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
    /*for(int i=0; i<n; i++)
    {
        v[i]=0;
    }*/
    dfs(v, adj_mat, n, s);
}