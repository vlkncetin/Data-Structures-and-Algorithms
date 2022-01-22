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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* last=head;
        ListNode* curr1=head;
        int len=0;
        while(curr1!=NULL)
        {
            len++;
            curr1=curr1->next;
        }
        int pos=0;
        n=len-n;
        if(n==0)
        {
            head=last->next;
            delete last;
            return head;
        }
        else
        {
            while(last->next!=NULL)
            {
               if(pos==n-1)
               {
                   ListNode* temp=last->next;
                   last->next=last->next->next;
                   delete temp;
                   break;
               }
               last=last->next;
               pos++;
            }
        }
        return head;
    }
};