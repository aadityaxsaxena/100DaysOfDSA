/*Problem Statement:
Given a binary tree, print its vertical order traversal. Nodes that lie on the same vertical line should be printed together from top to bottom and from left to right.
Input Format:
- First line contains integer N (number of nodes)
- Second line contains N space-separated integers representing level-order traversal (-1 indicates NULL)
Output Format:
- Print nodes column by column from leftmost to rightmost vertical line
Example:
Input:
7
1 2 3 4 5 6 7
Output:
4
2
1 5 6
3
7
Explanation:
Vertical lines are formed based on horizontal distance from root. Nodes sharing the same distance are printed together.*/

#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
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
        if (arr[i] != -1) {
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
void findMinMax(struct Node* root, int hd, int* min, int* max) {
    if (!root) return;
    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;
    findMinMax(root->left, hd - 1, min, max);
    findMinMax(root->right, hd + 1, min, max);
}
void printVertical(struct Node* root, int line, int hd) {
    if (!root) return;
    if (hd == line)
        printf("%d ", root->data);
    printVertical(root->left, line, hd - 1);
    printVertical(root->right, line, hd + 1);
}
void verticalOrder(struct Node* root) {
    int min = 0, max = 0;
    findMinMax(root, 0, &min, &max);
    for (int i = min; i <= max; i++) {
        printVertical(root, i, 0);
        printf("\n");
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    verticalOrder(root);
    return 0;
}