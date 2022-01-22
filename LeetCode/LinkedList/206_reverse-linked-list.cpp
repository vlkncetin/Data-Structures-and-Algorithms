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
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* newfirst=head;
        ListNode* afterLastNode=NULL;
        ListNode* lastNode=head;

        while(lastNode->next!=NULL)
        {
            lastNode=lastNode->next;
        }
        // 1->2->3->4->5->null => 5->4->3->2->1->null
        // 17->15->8->12->10->5->4->1->7->6->NULL
        while(newfirst!=lastNode)
        {
            if(lastNode->next==NULL)
            {
                newfirst=newfirst->next;
                ListNode* temp=head;
                temp->next=NULL;
                lastNode->next=temp;
                afterLastNode=temp;
            }
            else
            {
                newfirst=newfirst->next;
                ListNode* temp=head;
                temp->next=afterLastNode;
                lastNode->next=temp;
                afterLastNode=temp;
            }
            head=newfirst;
        } 
        return head;
    }
};