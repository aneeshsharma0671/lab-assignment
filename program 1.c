#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *newNode(int data)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
int max(int a, int b)
{
    if (a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}
int height(struct node *root)
{
    if(root==NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}
int check(struct node *root)
{
    int left = height(root->left);
    int right = height(root->right);
    if(abs(left-right)<=1 && check(root->left) && check(root->right))
    {
        return 1;
    }
    return 0;
}
int main(){
    struct node *root = newNode(1);
    root->right = newNode(2);
    root->right->right = newNode(3);
    root->right->right->right = newNode(4);
    root->right->right->right->right = newNode(5);
    root->right->right->right->right->right = newNode(6);
    if(check(root))
    {
        printf("Balanced tree\n");
    }
    else
    {
        printf("unbalanced tree\n");
    }
    return 0;
}

