#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int data){
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}

void PreOrder(struct node *root)
{
    if(root == NULL){
        return;
    }
    printf("%d \n",root->data);
    PreOrder(root->left);
    PreOrder(root->right);

}

int max(int a, int b)
{
    if(a>=b)
    {
        return a;
    }
    else
    {
        return b;
    }
    
}

int height(struct node *root){
    if(root == NULL){return 0;}
    return 1 + max(height(root->left), height(root->right));
}

struct node *converting(int arr[],int s,int l){
    if (s>l)
    {
        return NULL;
    }
    int m = (s+l)/2;
    struct node *root = newNode(arr[m]);
    root->left = converting(arr,s,m-1);
    root->right = converting(arr,m+1,l);
    return root;

}

int main(){
    int arr[] = {1,2,3,4,5,6};
    struct node *root = converting(arr,0,5);
    printf("printing tree in using preorder\n");
    PreOrder(root);
    printf("height= %d\n",height(root));
    return 0;
}
