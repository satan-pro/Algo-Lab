#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int front;
    int rear;
    int size;
    int* arr;
};

typedef struct Queue* queue;

int isEmpty(queue q)
{
    if(q->front==q->rear)
    {
        return 1;
    }
    return 0;
}

void enqueue(int data, queue q)
{
    if(q->rear!=(q->size-1))
    {
        q->arr[q->rear++] = data;
    }
}

int dequeue(queue q)
{
    if(q->front!=q->rear)
    {
        return q->arr[q->front++];
    }
}

int main()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = 0;
    int n;
    printf("Enter size of queue : ");
    scanf("%d", &n);
    q->size=n;

    int u;
    int i=0;
    int visited[7] = {0,0,0,0,0,0,0};

    int a[7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,0,1,0,0,0},
        {1,0,0,1,1,0,0},
        {1,1,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0},
    };

    printf("%d", i);
    visited[i] = 1;
    enqueue(i,q);
    while(!isEmpty(q))
    {
        int node = dequeue(q);
        for(int j=0; j<7; j++)
        {
            if(a[node][j]==1 && visited[j]==0)
            {
                printf("%d", j);
                enqueue(j, q);
                visited[j]=1;
            }
        }
    }


}