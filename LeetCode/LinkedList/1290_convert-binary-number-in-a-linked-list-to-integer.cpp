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
    int getDecimalValue(ListNode* head) {
        
        if(head==NULL)
            return 0;
        if(head->next==NULL && head->val==0)
            return 0;
        if(head->next==NULL && head->val==1)
            return 1;
        
        ListNode* current=head;
        int size=0;
        while(current!=NULL)
        {
            size++;
            current=current->next;
        }
        current=head;
        
        int num=0;
        int index=0;
        while(current!=NULL)
        {
            num+=pow(2,size-index++-1)*current->val;
            current=current->next;
        }
        
        return num;
    }
};