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
    void traverse(TreeNode* &root, int val)
    {
        if(root==NULL)
            return;
        
        if(root->left==NULL && val<root->val)
        {
            TreeNode* node=new TreeNode(val);
            root->left=node;
            return;
        }
        else if(root->left!=NULL && val<root->val)
        {
            traverse(root->left, val);
        }
        else if(root->right==NULL && val>root->val)
        {
            TreeNode* node=new TreeNode(val);
            root->right=node;
            return;
        }
        else if(root->right!=NULL && val>root->val)
        {
            traverse(root->right, val);
        }
        
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(preorder.empty())
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[0]);
        
        for(int i=1;i<preorder.size();i++)
        {
            traverse(root, preorder[i]);
        }
        
        return root;
    }
};