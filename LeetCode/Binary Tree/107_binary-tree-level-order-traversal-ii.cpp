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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root==NULL)
            return res;
        
        vector<int> level;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        TreeNode* curr;
        
        while(q.size()>1)
        {
            curr=q.front();
            q.pop();
            
            if(curr==NULL)
            {
                q.push(NULL);
                res.push_back(level);
                level.clear();
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
        
        if(!level.empty())
            res.push_back(level);
        
        vector<vector<int>> res2;
        
        for(int i=res.size()-1;i>=0;i--)
            res2.push_back(res[i]);
        
        return res2;
    }
};