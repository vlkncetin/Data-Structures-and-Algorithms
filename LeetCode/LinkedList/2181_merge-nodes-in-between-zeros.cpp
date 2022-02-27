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
    ListNode* mergeNodes(ListNode* head) {
        
        ListNode* curr=head->next;
        ListNode* res=NULL;
        ListNode* curr2=NULL;
        
        int sum=0;
        while(curr!=NULL)
        {
            if(curr->val==0)
            {
                ListNode* tmp=new ListNode(sum);
                if(res==NULL)
                {
                    res=tmp;
                    curr2=res;
                }
                else
                {
                    curr2->next=tmp;
                    curr2=curr2->next;
                }
                sum=0;
            }
            else
            {
                sum+=curr->val;
            }
            curr=curr->next;
        }
        
        return res;
    }
};