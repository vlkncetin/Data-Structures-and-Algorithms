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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        if(k==0)
            return head;
        
        ListNode* len=head;
        int x=0;
        while(len!=NULL)
        {
            x++;
            len=len->next;
        }
        if(x==k)
            return head;
        k=k%x;
        //k++;
        while(k!=0)
        {
            ListNode* curr=head;
            ListNode* prev=NULL;
            
            while(curr->next!=NULL)
            {
                prev=curr;
                curr=curr->next;
            }
            prev->next=NULL;
            curr->next=head;
            head=curr;
            
            k--;
        }
        return head;
    }
};