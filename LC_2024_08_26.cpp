// 590. N-ary Tree Postorder Traversal

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> result;
    vector<int> postorder(Node* root) {
        if ( root != NULL ) {
            for ( auto i : root->children ) {
                postorder(i);
            }
            result.push_back(root->val);
        }
        return result;
    }
};
