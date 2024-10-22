// 2583. Kth Largest Sum in a Binary Tree

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> nodeQueue;
        queue<int> levelQueue;
        map<int, long long> levelSum;
        nodeQueue.push(root);
        levelQueue.push(0);
        while ( !nodeQueue.empty() ) {
            TreeNode* node = nodeQueue.front();
            int level = levelQueue.front();
            levelSum[level] += node->val;
            if ( node != NULL ) {
                if ( node->left != NULL ) {
                    nodeQueue.push( node->left );
                    levelQueue.push( level+1 );
                }
                if ( node->right != NULL ) {
                    nodeQueue.push( node->right );
                    levelQueue.push( level+1 );
                }
            }
            nodeQueue.pop();
            levelQueue.pop();
        }
        if ( levelSum.size() < k )
            return -1; 
        priority_queue<long long> finalSum;
        for ( auto it = levelSum.begin(); it != levelSum.end(); it++ ) {
            finalSum.push(it->second);
        }
        for ( int i = 0; i < k - 1; i++ ) {
            finalSum.pop();
        }
        return finalSum.top();
    }
};
