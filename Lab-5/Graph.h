#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

typedef struct Node* node;

struct Graph{
    int vertices;
    int* inDegree;
    struct Node** list;
};

typedef struct Graph* graph;

node createNode(int data)
{
    node newNode =(node)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;

    return newNode;
}

graph createGraph(int vertex)
{
    graph g = (graph)malloc(sizeof(struct Graph));
    g->vertices = vertex;
    g->inDegree = (int*)calloc(g->vertices,sizeof(int));
    g->list = (node*)malloc(vertex*sizeof(node));

    for(int i=0; i<vertex; i++)
    {
        g->list[i]=NULL;
    }

    return g;
}

graph createEdgeUndirected(graph g, int src, int dest)
{
    node newNode = createNode(dest);
    newNode->next=g->list[src];
    g->list[src]=newNode;

    newNode = createNode(src);
    newNode->next=g->list[dest];
    g->list[dest]=newNode;

    return g;
}

graph createEdgeDirected(graph g, int src, int dest)
{
    node newNode = createNode(dest);
    newNode->next=g->list[src];
    g->list[src]=newNode;
    g->inDegree[dest]++;
    return g;
}

void showList(node n)
{
    while(n)
    {
        printf("%d->", n->data);
        n=n->next;
    }
    printf("\n");
}

void showGraph(graph g)
{
    for(int i=0; i<g->vertices; i++)
    {
        printf("%d : ", i);
        showList(g->list[i]);
    }
    printf("\n");
}