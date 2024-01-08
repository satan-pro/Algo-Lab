/*Write a program to construct a binary tree to support the following operations.
Assume no duplicate elements while constructing the tree.
i. Given a key, perform a search in the binary search tree. If the key is found
then display “key found” else insert the key in the binary search tree.
ii. Display the tree using inorder, preorder and post order traversal methods*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node* node;

node insert(node root, int data)
{
    if(root)
    {
        if(data<root->data)
        {
            root->left = insert(root->left, data);
        }
        else if(data>root->data)
        {
            root->right = insert(root->right, data);
        }
    }
    else{
        node new = (node)malloc(sizeof(struct Node));
        new->left=new->right = NULL;
        new->data = data;

        root=new;
    }
    return root;
}

int search(node root, int key)
{
    //printf("%d\n", root->data);
    if(key==root->data)
    {
        return 1;
    }
    else if(key<root->data)
    {
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
    return 0;
}

void inorder(node root)
{
    if(root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(node root)
{
    if(root)
    {
        printf("%d ", root->data);
        inorder(root->left);
        
        inorder(root->right);
    }
}

void postorder(node root)
{
    if(root)
    {
        inorder(root->left);
       
        inorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    node root = (node)malloc(sizeof(struct Node));
    root=NULL;
    int rs;
    do{
        printf("Enter your choice: \n1.Enter data\n2.Search\n3.Print Traversals\n");
        int ch;
        scanf("%d", &ch);
        int d;
        switch(ch)
        {
            case 1: printf("Enter data to enter : ");
                    scanf("%d", &d);
                    root=insert(root, d);
                    break;

            case 2: printf("Enter key to search : ");
                    scanf("%d", &d);
                    if(search(root, d))
                    {
                        printf("Search successfull!!\n");
                    }
                    else{ 
                        printf("Key not found\n");
                    }
                    break;

            case 3: printf("Inorder : ");
                    inorder(root);
                    printf("\n");
                    printf("Preorder : ");
                    preorder(root);
                    printf("\n");
                    printf("Preorder : ");
                    postorder(root);
                    printf("\n");
                    break;
        }
        printf("Do you want to continue? (1/0)");
        scanf("%d", &rs);
    }while(rs);
    return 0;
}