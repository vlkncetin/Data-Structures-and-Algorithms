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
    ListNode* swapNodes(ListNode* head, int k) {
        
        if(head==NULL)
            return NULL;
        ListNode* curr=head;
        
        int i=1;
        int len=0;
        int firstK=-1;
        int secondK=-1;
        
        while(curr!=NULL)
        {
            len++;
            curr=curr->next;
        }
        
        ListNode* curr2=head;
        while(curr2!=NULL)
        {
            if(i==k)
            {
                firstK=curr2->val;
                break;
            }
            i++;
            curr2=curr2->next;
        }
        i=1;
        ListNode* curr3=head;
        while(curr3!=NULL)
        {
            if(i==len-k+1)
            {
                secondK=curr3->val;
                break;
            }
            i++;
            curr3=curr3->next;
        }
        curr2->val=secondK;
        curr3->val=firstK;
        return head;
    }
    
};