/*Find total number of nodes in a binary tree and analyze its efficiency. Obtain the
experimental result of order of growth and plot the result.*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};
typedef struct Node* node;

static int count=0;
static int opcount=0;

node createNode(int data)
{
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=NULL;
    newNode->right=NULL;
}

node leftBinaryTree(node root, int data)
{   
    if(!root)
    {
        root=createNode(data);
    }
    else if(root->left==NULL)
    {
        root->left=leftBinaryTree(root->left, data);
    }
    else
    {
        root->right = leftBinaryTree(root->right, data);
    }
    return root;
}

int countNodes(node root)
{
    opcount++;
    if(!root)
    {
        return 0;
    }
    return 1+countNodes(root->left)+countNodes(root->right);
}

void displayTree(node root)
{
    if(root)
    {
        displayTree(root->left);
        printf("%d ", root->data);
        displayTree(root->right);
    }
}

int main()
{
    node root = (node)malloc(sizeof(struct Node));
    root=NULL;
    int ch,n;
    
    do
    {
        printf("Enter value of node (-1 to terminate): ");
        scanf("%d", &n);
        root=leftBinaryTree(root, n);
        printf("Continue ? (1/0) :");
        scanf("%d", &ch);
    }while(ch>0);

    int c = countNodes(root);
    printf("Count of nodes : %d\nOpcount : %d\n", c, opcount);
    return 0;
}

