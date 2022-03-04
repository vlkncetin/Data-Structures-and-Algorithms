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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        
        if(root==NULL)
            return res;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        
        vector<int> treeLevel;
        
        TreeNode* curr;
        
        while(q.size()>1)
        {
            curr=q.front();
            q.pop();
            if(curr==NULL)
            {
                q.push(NULL);
                res.push_back(treeLevel);
                treeLevel.clear();
            }
            else
            {
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
                
                treeLevel.push_back(curr->val);
            }

        }
        if(!treeLevel.empty())
            res.push_back(treeLevel);
        return res;
    }
};