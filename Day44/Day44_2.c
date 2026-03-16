/*Given the root of a binary tree, return the preorder traversal of its nodes' values.
Example 1:
Input: root = [1,null,2,3]
Output: [1,2,3]
Explanation:
Example 2:
Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
Output: [1,2,4,5,6,7,3,8,9]
Explanation:
Example 3:
Input: root = []
Output: []
Example 4:
Input: root = [1]
Output: [1]
*/

void preorder(struct TreeNode* root, int* result, int* index) {
    if (root == NULL)
        return;
    result[*index] = root->val;
    (*index)++;
    preorder(root->left, result, index);
    preorder(root->right, result, index);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(1000 * sizeof(int));  // enough for constraints
    int index = 0;
    preorder(root, result, &index);
    *returnSize = index;
    return result;
}