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
    void traverse(TreeNode* root,vector<int>& vec)
    {
        if(root==NULL)
            return;
        
        vec.push_back(root->val);
        traverse(root->left,vec);
        traverse(root->right,vec);
    }
    
    void flatten(TreeNode* root) {
        
        if(root==NULL)
            return;
        
        vector<int> vec;
        traverse(root,vec);
        
        TreeNode* curr=nullptr;
        TreeNode* result=nullptr;
        
        for(int i=0;i<vec.size();i++)
        {
            TreeNode* tmp=new TreeNode(vec[i]); 
            if(result==nullptr)
            {
                result=tmp;
                curr=result;
            }
            else
            {
                curr->right=tmp;
                curr=curr->right;
            }
        }
        
        root->left=result->left;
        root->right=result->right;
    }
};