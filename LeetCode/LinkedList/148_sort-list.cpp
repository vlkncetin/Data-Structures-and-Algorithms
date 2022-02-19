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
    ListNode* sortList(ListNode* head) {
        
        vector<int> vec;
        ListNode* curr=head;
        
        while(curr!=NULL)
        {
            vec.push_back(curr->val);
            curr=curr->next;
        }
        
        sort(vec.begin(),vec.end());
        
        ListNode* res=NULL;
        curr=NULL;
        
        for(int i=0;i<vec.size();i++)
        {
            ListNode* temp=new ListNode(vec[i]);
            if(res==NULL)
            {
                res=temp;
                curr=res;
            }
            else
            {
                curr->next=temp;
                curr=curr->next;
            }
        }
        
        return res;
    }
};