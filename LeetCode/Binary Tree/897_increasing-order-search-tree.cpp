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
        
        traverse(root->left);
        m_vec.push_back(root->val);
        traverse(root->right);
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        
        if(root==NULL)
            return NULL;
        
        traverse(root);
        
        TreeNode* newtree=new TreeNode(m_vec[0]);
        TreeNode* current=newtree;
        
        for(int i=1;i<m_vec.size();i++)
        {
            TreeNode* node=new TreeNode(m_vec[i]);
            current->right=node;
            current=current->right;
        }
        
        return newtree;
    }
    
private:
    vector<int> m_vec;
    
};