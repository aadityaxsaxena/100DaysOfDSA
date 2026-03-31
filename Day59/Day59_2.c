/*Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.
Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]
*/

#include <stdlib.h>
int map[6001];
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}
struct TreeNode* build(int* inorder, int* postorder, int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd) return NULL;
    int val = postorder[(*postIndex)--];
    struct TreeNode* root = newNode(val);
    int idx = map[val + 3000];
    root->right = build(inorder, postorder, idx + 1, inEnd, postIndex);
    root->left  = build(inorder, postorder, inStart, idx - 1, postIndex);
    return root;
}
struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + 3000] = i;
    }
    int postIndex = postorderSize - 1;
    return build(inorder, postorder, 0, inorderSize - 1, &postIndex);
}