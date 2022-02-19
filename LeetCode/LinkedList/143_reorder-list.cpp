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
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    void reorderList(ListNode* head) {
        
        ListNode* mid = head;
        ListNode* fast = head;
        
        while(fast->next!=NULL && fast->next->next!=NULL)
        {
            mid=mid->next;
            fast = fast->next->next;
        }
        
        ListNode* secondHalf = mid->next;
        mid->next=NULL;
        
        ListNode* reversedSecondHalf = reverseList(secondHalf);
        
        ListNode* curr=head;
        while(curr!=NULL && reversedSecondHalf!=NULL)
        {
            ListNode* temp = curr->next;
            curr->next=reversedSecondHalf;
            
            reversedSecondHalf=reversedSecondHalf->next;
            curr->next->next=temp;
            curr = temp;
        }
    }
};