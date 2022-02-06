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
    void traverse(TreeNode* root, vector<int>& vec)
    {
        if(root==NULL)
            return;
        
        vector<int>::iterator found=find(vec.begin(),vec.end(),root->val);
        if(found==vec.end())
            vec.push_back(root->val);
        traverse(root->left, vec);
        traverse(root->right, vec);
    }
    int findSecondMinimumValue(TreeNode* root) {
        
        int res=-1;
            
        if(root==NULL)
            return res;
        
        vector<int> vec;
        traverse(root, vec);
        
        if(vec.size()<2)
            return -1;
        
        sort(vec.begin(),vec.end());
        
        for(int i=0;i<vec.size();i++)
            cout<<vec[i]<<" ";
        
        return vec[1];
    }
};