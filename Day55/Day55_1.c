/*Problem Statement:
Print the nodes visible when the binary tree is viewed from the right side.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)
Output Format:
- Print right view nodes
Example:
Input:
7
1 2 3 4 5 -1 6
Output:
1 3 6
Explanation:
At each level, the rightmost node is visible from the right view.*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
void rightViewUtil(struct Node* root, int level, int *maxLevel) {
    if (root == NULL)
        return;
    if (level > *maxLevel) {
        printf("%d ", root->data);
        *maxLevel = level;
    }
    rightViewUtil(root->right, level + 1, maxLevel);
    rightViewUtil(root->left, level + 1, maxLevel);
}
void rightView(struct Node* root) {
    int maxLevel = 0;
    rightViewUtil(root, 1, &maxLevel);
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;
    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];
        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    struct Node* root = buildTree(arr, n);
    rightView(root);
    return 0;
}