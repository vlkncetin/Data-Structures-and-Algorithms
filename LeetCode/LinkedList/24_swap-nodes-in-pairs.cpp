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
    ListNode* swapPairs(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;

        ListNode* current=head;
        ListNode* prev=head;

        while(current->next!=NULL)
        {
            int data1=current->val;
            int data2=current->next->val;
            current->val=data2;
            current->next->val=data1;

            if(current->next->next!=NULL)
                current=current->next->next;
            else
                current=current->next;
        }
        return head;
    }
};