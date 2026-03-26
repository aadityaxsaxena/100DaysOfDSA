/*Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
Example 2:
Input: root = [1]
Output: [[1]]
Example 3:
Input: root = []
Output: []
*/

#include <stdlib.h>
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }
    struct TreeNode* queue[2000];
    int front = 0, rear = 0;
    int** result = (int**)malloc(sizeof(int*) * 2000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 2000);
    enqueue:
    queue[rear++] = root;
    int level = 0;
    while (front < rear) {
        int size = rear - front;
        result[level] = (int*)malloc(sizeof(int) * size);
        (*returnColumnSizes)[level] = size;
        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];
            int index = (level % 2 == 0) ? i : (size - 1 - i);
            result[level][index] = node->val;
            if (node->left)  queue[rear++] = node->left;
            if (node->right) queue[rear++] = node->right;
        }
        level++;
    }
    *returnSize = level;
    return result;
}