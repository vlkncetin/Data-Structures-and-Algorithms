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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root==NULL)
            return res;
        
        vector<int> level;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        TreeNode* curr;
        
        bool fromLeft=true;
        
        while(q.size()>1)
        {
            curr=q.front();
            q.pop();
            
            if(curr==NULL)
            {
                if(!fromLeft)
                {
                    reverse(level.begin(),level.end());
                }
                res.push_back(level);
                fromLeft=!fromLeft;
                level.clear();
                q.push(NULL);
            }
            else
            {
                level.push_back(curr->val);
                
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        
        if(level.size()>0)
        {
            if(!fromLeft)
            {
                reverse(level.begin(),level.end());
            }
            res.push_back(level);
        }
            
        return res;
    }
};