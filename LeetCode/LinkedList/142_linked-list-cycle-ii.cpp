/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Node{
    public:
        int data;
        Node* next;
        bool traversed=false;
};
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(head==NULL)
            return NULL;
        else if(head->next==NULL)
            return NULL;
        else if(head->next==NULL)
            return NULL;
        else if(head->next==head)
            return head;
        else if(head->next->next==head)
        {
            return head;
        }
        
        ListNode *slow_p = head, *fast_p = head;

        while (slow_p!=NULL && fast_p!=NULL && fast_p->next!=NULL) {

            fast_p = fast_p->next->next;
            slow_p = slow_p->next;

            if (slow_p == fast_p) {
                break;
            }
        }
        if(slow_p==NULL)
            return NULL;
        if(fast_p==NULL)
            return NULL;
        //check the entry point 
        fast_p = head; 
        while(fast_p !=slow_p)
        {
            if(slow_p->next==NULL)
                return NULL;
            if(fast_p->next==NULL)
                return NULL;
            fast_p=fast_p->next; 
            slow_p=slow_p->next; 
        }
        return slow_p;
    }
};