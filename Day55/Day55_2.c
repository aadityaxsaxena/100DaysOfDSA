/*Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
Example 1:
Input: root = [1,2,3,null,5,null,4]
Output: [1,3,4]
Explanation:
Example 2:
Input: root = [1,2,3,4,null,null,null,5]
Output: [1,3,4,5]
Explanation:
Example 3:
Input: root = [1,null,3]
Output: [1,3]
Example 4:
Input: root = []
Output: []*/

#include <stdio.h>
#include <stdlib.h>
void dfs(struct TreeNode* root, int level, int* result, int* returnSize) {
    if (root == NULL)
        return;
    if (level == *returnSize) {
        result[*returnSize] = root->val;
        (*returnSize)++;
    }
    dfs(root->right, level + 1, result, returnSize);
    dfs(root->left, level + 1, result, returnSize);
}
int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));
    *returnSize = 0;
    dfs(root, 0, result, returnSize);
    return result;
}