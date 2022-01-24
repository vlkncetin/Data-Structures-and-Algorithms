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
    ListNode* deleteMiddle(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return NULL;
        
        ListNode* current=head;
        int lenght=0;
        while(current!=NULL)
        {
            lenght++;
            current=current->next;
        }

        lenght=lenght/2;

        current=head;
        ListNode* prev=NULL;
        int i=0;
        while(current!=NULL)
        {
            if(i==lenght)
            {
                ListNode* temp=current;
                prev->next=current->next;
                delete current;
                return head;
            }
            prev=current;
            current=current->next;
            i++;
        }
        
        return head;
    }
};