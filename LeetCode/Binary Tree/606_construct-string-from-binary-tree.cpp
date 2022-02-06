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
    void preorderTraverse(TreeNode* root, string& s)
    {
        if(root == NULL)
            return;
        
        if(root->left==NULL && root->right!=NULL)
        {
            s+="()";
        }
        if(root->left)
        {
            s+="(" + to_string(root->left->val);
            preorderTraverse(root->left,s);
            s.push_back(')');
        }
        if(root->right)
        {
            s+="(" + to_string(root->right->val);
            preorderTraverse(root->right,s);
            s.push_back(')');
        }         
    }
    
    string tree2str(TreeNode* root) {
        string res = "";
        res+=to_string(root->val);
        preorderTraverse(root,res);
        
        return res;
    }
};