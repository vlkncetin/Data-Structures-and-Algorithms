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
    int result=0;
    
    int sumRootToLeaf(TreeNode* root) {
        int buff = 0;
        traverseHelper(root, buff);
        return result;    
    }
    
    void traverseHelper(TreeNode *root, int buff)
    {
        buff = buff*2 + root->val;
        if(!root->left && !root->right)
        {
            result += buff;
            return;
        }
        
        if(root->left)
            traverseHelper(root->left, buff);
        if(root->right)
            traverseHelper(root->right, buff);
    }
};