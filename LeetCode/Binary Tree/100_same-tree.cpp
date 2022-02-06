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
    void traverse(TreeNode* p, string& s)
    {
        if(p==NULL)
            return;
        
        stringstream ss;
        ss<<s<<p->val;
        if(p->left==NULL)
            ss<<"x";
        else if(p->right==NULL)
            ss<<"o";
        else
            ss<<".";
        s=ss.str();
        traverse(p->left,s);
        traverse(p->right,s);
            
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        
        string s1="",s2="";
        traverse(p,s1);
        traverse(q,s2);
        
        if(s1!=s2)
            return false;
        return true;
    }
};