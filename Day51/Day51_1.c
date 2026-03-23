/*Problem Statement:
Find the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree.
Input Format:
- First line contains integer N
- Second line contains N space-separated integers
- Third line contains two node values
Output Format:
- Print the LCA value
Example:
Input:
7
6 2 8 0 4 7 9
2 8
Output:
6*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);   
    return root;
}
struct Node* findLCA(struct Node* root, int n1, int n2) {
    while (root != NULL) {
        if (n1 < root->data && n2 < root->data)
            root = root->left;
        else if (n1 > root->data && n2 > root->data)
            root = root->right;
        else
            return root;
    }
    return NULL;
}
int main() {
    int n, x, i, n1, n2;
    struct Node* root = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }
    scanf("%d %d", &n1, &n2);
    struct Node* lca = findLCA(root, n1, n2);
    if (lca != NULL)
        printf("%d\n", lca->data);
    return 0;
}