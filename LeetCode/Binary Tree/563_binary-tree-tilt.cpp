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
    int traverse(TreeNode* root, int& sum)
    {
        if(root==NULL)
            return 0;
        
        int L=traverse(root->left, sum);
        int R=traverse(root->right, sum);
        
        sum+=abs(R-L);
        
        return L + R + root->val;
        
    }
    int findTilt(TreeNode* root) {
        
        int sum=0;
        traverse(root,sum);
        return sum;
    }
};