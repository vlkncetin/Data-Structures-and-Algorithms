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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        TreeNode* curr;
        
        int sum=0;
        int max=INT_MIN;
        int levelOfMax=0;
        int level=0;
        
        while(q.size()>1)
        {
            curr=q.front();
            q.pop();
            
            if(curr==NULL)
            {
                level++;
                if(sum>max)
                {
                    max=sum;
                    levelOfMax=level;
                }
                sum=0;
                q.push(NULL);
            }
            else
            {
                sum+=curr->val;
                
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        
        if(sum>max)
        {
            levelOfMax=++level;
        }
        
        return levelOfMax;
    }
};