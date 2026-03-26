/*Problem Statement:
Perform zigzag (spiral) level order traversal of a binary tree. Alternate levels should be traversed left-to-right and right-to-left.
Input Format:
- First line contains integer N
- Second line contains level-order traversal (-1 indicates NULL)
Output Format:
- Print traversal in zigzag order
Example:
Input:
7
1 2 3 4 5 6 7
Output:
1 3 2 4 5 6 7
Explanation:
Level 1 is printed left-to-right, level 2 right-to-left, and so on.*/

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
struct Node* queue[1000];
int front = 0, rear = 0;
void enqueue(struct Node* node) {
    queue[rear++] = node;
}
struct Node* dequeue() {
    return queue[front++];
}
int isEmpty() {
    return front == rear;
}
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;
    struct Node* root = newNode(arr[0]);
    enqueue(root);
    int i = 1;
    while (!isEmpty() && i < n) {
        struct Node* curr = dequeue();
        if (arr[i] != -1) {
            curr->left = newNode(arr[i]);
            enqueue(curr->left);
        }
        i++;
        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            enqueue(curr->right);
        }
        i++;
    }
    return root;
}
void zigzagTraversal(struct Node* root) {
    if (!root) return;
    front = rear = 0;
    enqueue(root);
    int leftToRight = 1;
    while (!isEmpty()) {
        int size = rear - front;
        int arr[1000];
        for (int i = 0; i < size; i++) {
            struct Node* curr = dequeue();
            int index = leftToRight ? i : (size - 1 - i);
            arr[index] = curr->data;
            if (curr->left) enqueue(curr->left);
            if (curr->right) enqueue(curr->right);
        }
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
        leftToRight = !leftToRight;
    }
}
int main() {
    int n;
    scanf("%d", &n);
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = buildTree(arr, n);
    zigzagTraversal(root);
    return 0;
}