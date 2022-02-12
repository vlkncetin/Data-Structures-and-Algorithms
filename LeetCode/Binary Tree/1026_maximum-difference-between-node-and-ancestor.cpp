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
    void traverse(TreeNode* root, int maxVal, int minVal, int& diff)
    {
        if(root == NULL)
            return;
        
        diff = max(diff, max(abs(root->val-minVal), abs(root->val-maxVal)));
        
        if(root->val < minVal)
            minVal = root->val;
        
        if(root->val > maxVal)
            maxVal = root->val;
        
        traverse(root->left, maxVal, minVal, diff);
        traverse(root->right, maxVal, minVal, diff);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int maxVal = root->val;
        int minVal = root->val;
        int result = 0;
        
        traverse(root, maxVal, minVal, result);
        
        return result;
        
    }
};