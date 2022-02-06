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
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> vec;
        traverse(root, vec);
        
        for(int i=0;i<vec.size();i++)
        {
            for(int j=0;j<vec.size();j++)
            {
                if(i==j)
                    continue;
                if(vec[i]+vec[j]==k)
                    return true;
            }
        }
        
        return false;
    }
};