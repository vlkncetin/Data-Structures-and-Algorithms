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
    void transverse(TreeNode* root, vector<int>& vec)
    {
        if(root==NULL)
            return;
        
        transverse(root->left, vec);
        
        vec.push_back(root->val);
        
        transverse(root->right, vec);
    }
    int kthSmallest(TreeNode* root, int k) {
        
        vector<int> m_vec;
        transverse(root, m_vec);
        
        return m_vec[k-1];
    }
    
};