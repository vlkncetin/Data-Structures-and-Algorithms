/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root==NULL)
            return NULL;
        
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        
        vector<Node*> level;
        
        Node* curr=NULL;
        
        while(q.size()>1)
        {
            curr=q.front();
            q.pop();
            
            if(curr==NULL)
            {
                for(int i=0;i<level.size()-1;i++)
                {
                    level[i]->next=level[i+1];
                }
                level[level.size()-1]->next=NULL;
                level.clear();
                q.push(NULL);
            }
            else
            {
                level.push_back(curr);
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        
        for(int i=0;i<level.size()-1;i++)
        {
            level[i]->next=level[i+1];
        }
        level[level.size()-1]->next=NULL;
        
        return root;
    }
};