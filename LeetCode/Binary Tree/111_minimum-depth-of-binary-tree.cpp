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
    
    int minDepth(TreeNode* root) {
        
        if(root==NULL)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        TreeNode* curr;
        int depth=1;
        
        while(q.size()>1)
        {
            curr=q.front();
            q.pop();
            
            if(curr==NULL)
            {
                depth++;
                q.push(NULL);
            }
            else
            {
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                
                if(curr->right==NULL && curr->left==NULL)
                    break;
            }
            
            
        }
        
        return depth;
    }
};