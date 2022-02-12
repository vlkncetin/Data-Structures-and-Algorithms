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
class FindElements {
public:
    FindElements(TreeNode* root) {
        m_root=root;
        if(m_root!=NULL)
        {
            m_root->val=0;
            m_vec.push_back(0);
        }
        
        traverse(m_root);
    }
    
    void traverse(TreeNode* root)
    {
        if(root==NULL)
            return;
        
        if(root->left!=NULL)
        {
            root->left->val=root->val*2+1;
            m_vec.push_back(root->left->val);
            traverse(root->left);
        }
        if(root->right!=NULL)
        {
            root->right->val=root->val*2+2;
            m_vec.push_back(root->right->val);
            traverse(root->right);
        }
    }
        
    bool find(int target) {
        
        vector<int>::iterator it=std::find(m_vec.begin(),m_vec.end(),target);
        
        if(it!=m_vec.end())
            return true;
        
        return false;
    }
    
private:
    TreeNode* m_root;
    vector<int> m_vec;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */