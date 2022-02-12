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
    void traverse(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        m_set.insert(root->val);
        if(m_set.size()>1)
            return;
        traverse(root->left);
        traverse(root->right);
    }
    bool isUnivalTree(TreeNode* root) {
        
        traverse(root);
        
        if(m_set.size()>1)
            return false;
        
        return true;
    }
    
private:
    set<int> m_set;
};