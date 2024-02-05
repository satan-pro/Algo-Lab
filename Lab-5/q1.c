/*Write a program to determine the Topological sort of a given graph using
i. Depth-First technique
ii. Source removal technique*/
#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "stack.h"

int vertices;
void dfsTopological(int* visited, int i, graph g, stack s)
{
    visited[i]=1;
    node head=g->list[i];
    while(head)
    {
        if(!visited[head->data])
        {
            dfsTopological(visited, head->data, g, s);
        }
        head=head->next;
    }
    push(s, i);
}

int sourceRemoval(int* visited2, graph g, stack s1, int i, int count)
{
    if(g->inDegree[i]==0)
    {
        if(!visited2[i])
        {
            push(s1, i);
            count++;
            visited2[i]=1;
            node head=g->list[i];
            while(head)
            {
                int curr = head->data;
                g->inDegree[curr]--;
                head=head->next;
            }
        }
    }
    return count;
}

int main()
{
    printf("Enter no of vertices : ");
    scanf("%d", &vertices);

    graph g = createGraph(vertices);
    stack s = createStack(vertices);
    stack s1 = createStack(vertices);
    int src=0;
    int dest=0;

    printf("Enter the source and destination (-1 to exit)\n");
    while(src>=0 && dest>=0)
    {
        scanf("%d %d", &src, &dest);
        g = createEdgeDirected(g, src, dest);
    }
  
    int visited[vertices];
    int visited2[vertices];
    for(int i=0; i<vertices; i++)
    {
        visited[i]=0;
        visited2[i]=0;
    }

    for(int i=0; i<g->vertices; i++)
    {
        if(!visited[i])
        {
            dfsTopological(visited, i, g, s);
        }
    }
    int count=0;
    while(count<g->vertices)
    {
        for(int i=0; i<g->vertices; i++)
        {
            count = sourceRemoval(visited2, g, s1, i, count);
        }
    }

    printf("Topological using DFS : ");
    while(!isEmpty(s))
    {
        printf("%d ", pop(s));
    }

    printf("\nTopological using Source Removal : ");
    for(int i=0; i<vertices; i++)
    {
        printf("%d ", s1->arr[i]);
    }
}

