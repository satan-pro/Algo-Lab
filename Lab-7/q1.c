/*Write a program to create the AVL tree by iterative insertion.*/
#include <stdio.h>
#include <stdlib.h>
 
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};
typedef struct Node* node;
 
int getHeight(node n){
    if(n==NULL)
        return 0;
    return n->height;
}
 
node createNode(int key){
    node newNode = (node)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
 
int max (int a, int b){
    return (a>b)?a:b;
}
 
int getBalanceFactor(node n){
    if(n==NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}
 
node rightRotate(node y){
    node x = y->left;
    node T2 = x->right;
 
    x->right = y;
    y->left = T2;
 
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
    return x;
}
 
node leftRotate(node x){
    node y = x->right;
    node T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
    return y;
}
 
node insert(node root, int key){
    if (root == NULL)
        return  createNode(key);
 
    if (key < root->key)
        root->left  = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);
 
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int bf = getBalanceFactor(root);
 
    // Left Left Case
        if(bf>1 && key < root->left->key){
            return rightRotate(root);
        }
    // Right Right Case
        if(bf<-1 && key > root->right->key){
            return leftRotate(root);
        }
    // Left Right Case
    if(bf>1 && key > root->left->key){
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    // Right Left Case
    if(bf<-1 && key < root->right->key){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    return root;
}
 
void inorder(node root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main()
{
    node root = (node)malloc(sizeof(struct Node));
    root=NULL;
    int n, ch;
    do
    {
        printf("Enter value of node (-1 to terminate): ");
        scanf("%d", &n);
        root=insert(root, n);
        printf("Continue ? (1/0) :");
        scanf("%d", &ch);
    }while(ch>0);
    inorder(root);
    printf("Enter key to be searched : ");
    scanf("%d", &n);
    int pred = inorderPredecessor(n, root);
    int succ = inorderSuccesor(n, root);
    printf("Predecessor : %d\nSuccessor : %d\n", pred, succ);
    return 0;
}
