/*Write a program to implement the following graph representations and display
them.
i. Adjacency list
ii. Adjacency matrix*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
typedef struct Node* node;

struct Graph{
    int vertices;
    struct Node** adjlist;
    int** adjmat;
};
typedef struct Graph* graph;

node createNode(int data)
{
    node new = (node)malloc(sizeof(struct Node));
    new->next=NULL;
    new->data = data;
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

graph createGraph(int numvertex)
{
    graph g = (graph)malloc(sizeof(struct Graph));
    g->vertices = numvertex;

    g->adjlist = (struct Node**)malloc(numvertex*sizeof(struct Node*));

    for(int i=0; i<numvertex; i++)
    {
        g->adjlist[i]=NULL;
    }

    g->adjmat = (int**)malloc(numvertex*sizeof(int*));

    for(int i=0; i<numvertex; i++)
    {
        for(int j=0; j<numvertex; j++)
        {
            g->adjmat[i]=(int*)malloc(numvertex*sizeof(int));
        }
    }

    return g;
}

graph createEdge(graph g, int org, int dest)
{
    node newNode = createNode(dest);
    newNode->next=g->adjlist[org];
    g->adjlist[org]=newNode;

    newNode = createNode(org);
    newNode->next=g->adjlist[dest];
    g->adjlist[dest]=newNode;

    g->adjmat[org][dest] = 1;
    g->adjmat[dest][org] = 1;

    return g;
}

void showGraph(graph g)
{
    for(int i=0; i<g->vertices; i++)
    {
        printf("%d : ",i);
        showList(g->adjlist[i]);
    }
    printf("\n");
    
    for(int i=0; i<g->vertices; i++)
    {
        for(int j=0; j<g->vertices; j++)
        {
            printf("%d", g->adjmat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter number of vertices : ");
    scanf("%d", &n);

    graph g = createGraph(n);

    for(int i=0; i<n; i++)
    {
        int ans;
        for(int j=i+1; j<n; j++)
        {
            printf("Vertex %d connected to vertex %d ?(1/0) : ",i,j);
            scanf("%d", &ans);
            if(ans)
            {
                g = createEdge(g, i, j);
            }
        }
    }

    showGraph(g);
}