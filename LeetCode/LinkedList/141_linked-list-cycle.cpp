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
    bool hasCycle(ListNode *list) {
        ListNode *slow_p = list, *fast_p = list;
    
        if(list==NULL)
            return false;
        else if(list->next==NULL)
            return false;

        while (slow_p!=NULL && fast_p!=NULL && fast_p->next!=NULL) {

            fast_p = fast_p->next->next;
            slow_p = slow_p->next;

            if (slow_p == fast_p) {
                return true;
            }
        }
        return false;
    }
};