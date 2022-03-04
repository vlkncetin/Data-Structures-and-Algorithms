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
    vector<double> averageOfLevels(TreeNode* root) {
        
        vector<double> res;
        
        if(root==NULL)
            return res;
        
        queue<TreeNode*> q;
        
        q.push(root);
        q.push(NULL);
        
        long long int sum=0;
        int counter=0;
        
        TreeNode* curr;
        
        while(q.size()>1)
        {
            curr=q.front();
            q.pop();
            
            if(curr==NULL)
            {
                double avg=(double)sum/counter;
                res.push_back(avg);
                q.push(NULL);
                sum=0;
                counter=0;
            }
            else
            {
                sum+=curr->val;
                counter++;
                
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        
        if(counter>0)
        {
            double avg=(double)sum/counter;
            res.push_back(avg);
        }
        
        return res;
    }
};