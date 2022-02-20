/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        if(lists.empty())
            return NULL;
        
        if(lists.size()==1 && lists[0]==NULL)
            return NULL;
        
        vector<int> vec;
        for(int i=0;i<lists.size();i++)
        {
            ListNode *current=lists[i];
            while(current!=NULL)
            {
                vec.push_back(current->val);
                current=current->next;
            }
        }
        
        sort(vec.begin(),vec.end());
        
        ListNode *res=NULL;
        ListNode *curr=NULL;
        
        for(int i=0;i<vec.size();i++)
        {
            if(res==NULL)
            {
                ListNode *tmp=new ListNode(vec[i]);
                res=tmp;
                curr=res;
            }
            else
            {
                ListNode *tmp=new ListNode(vec[i]);
                curr->next=tmp;
                curr=curr->next;
            }
            
        }
        
        return res;
    }
};