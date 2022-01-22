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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode* current=head;
        ListNode* prev=NULL;
        if(head==NULL)
            return NULL;
        
        while(current!=NULL)
        {
            if(current->val==val)
            {
                ListNode* temp=current;
                if(prev==NULL)
                {
                    current=current->next;
                    head=current;
                }
                else if(current->next!=NULL)
                {
                    prev->next=current->next;
                    current=current->next;
                }
                else
                {
                    prev->next=NULL;
					current=NULL;
                }
                delete temp;
            }
            else
            {
                prev=current;
                current=current->next;
            }
        }
        return head;
    }
};