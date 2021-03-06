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
    void preorderTraverse(Node* root, vector<int>& vec)
    {
        if(root==NULL)
            return;
               
        vec.push_back(root->val);
        for(int i=0;i<root->children.size();i++)
            preorderTraverse(root->children[i],vec);
        
    }
    vector<int> preorder(Node* root) {
        
        vector<int> res;
        preorderTraverse(root,res);
        return res;
    }
};