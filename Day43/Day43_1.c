/*Problem Statement:
Construct a Binary Tree from the given level-order traversal.
Input Format:
- First line contains integer N
- Second line contains N space-separated integers (-1 represents NULL)
Output Format:
- Print inorder traversal of the constructed tree
Example:
Input:
7
1 2 3 4 5 -1 6
Output:
4 2 5 1 3 6*/

#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *left,*right;
}Node;
Node* newNode(int data){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=data;
    temp->left=temp->right=NULL;
    return temp;
}
void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
int main(){
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    Node* nodes[n];
    for(i=0;i<n;i++){
        if(a[i]==-1) nodes[i]=NULL;
        else nodes[i]=newNode(a[i]);
    }
    for(i=0;i<n;i++){
        if(nodes[i]!=NULL){
            int l=2*i+1;
            int r=2*i+2;
            if(l<n) nodes[i]->left=nodes[l];
            if(r<n) nodes[i]->right=nodes[r];
        }
    }
    inorder(nodes[0]);
    return 0;
}