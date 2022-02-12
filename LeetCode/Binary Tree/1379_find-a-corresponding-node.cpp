/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void traverse(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &resultNode){
        
        if(!original) 
            return;
        
        if(original->left) 
            traverse(original->left,cloned->left,target,resultNode);
        
        if(original==target) 
            resultNode=cloned;
        
        if(original->right) 
            traverse(original->right,cloned->right,target,resultNode);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        TreeNode* resultNode;
        
        traverse(original,cloned,target,resultNode);
        
        return resultNode;
    }
    
};