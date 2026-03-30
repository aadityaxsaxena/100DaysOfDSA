/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.
Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]
*/

#include <stdlib.h>
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
int find(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}
struct TreeNode* build(int* preorder, int* inorder, int start, int end, int* preIndex) {
    if (start > end)
        return NULL;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[(*preIndex)++];
    root->left = root->right = NULL;
    if (start == end)
        return root;
    int inIndex = find(inorder, start, end, root->val);
    root->left = build(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = build(preorder, inorder, inIndex + 1, end, preIndex);
    return root;
}
struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    int preIndex = 0;
    return build(preorder, inorder, 0, inorderSize - 1, &preIndex);
}