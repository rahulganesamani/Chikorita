// 1038. Binary Search Tree to Greater Sum Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int total = 0;
    void printInNode(TreeNode* root) {
        if ( root == NULL ) {
            return;
        }
        bstToGst(root->right);
        root->val += total;
        total = root->val;
        bstToGst(root->left);
    }
    TreeNode* bstToGst(TreeNode* root) {
        printInNode(root);
        return root;
    }
};
