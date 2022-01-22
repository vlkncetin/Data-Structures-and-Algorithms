/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode* current1=headA;
        
        if(headA==NULL || headB==NULL)
            return NULL;

        ListNode* res=new ListNode();
        
        while(current1!=NULL)
        {
            ListNode* current2=headB;
            while(current2!=NULL)
            {
                if(current1==current2)
                {
                    return current1;
                    
                }
                current2=current2->next;
            }
            current1=current1->next;
        }

        return NULL;
    }
};