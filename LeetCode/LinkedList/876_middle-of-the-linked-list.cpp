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
    ListNode* middleNode(ListNode* head) {
        ListNode* current=head;
        int lenght=0;
        while(current!=NULL)
        {
            lenght++;
            current=current->next;
        }

        lenght=lenght/2;

        current=head;
        int i=0;
        while(current!=NULL)
        {
            if(i==lenght)
                return current;
            current=current->next;
            i++;
        }
        
        return NULL;
    }
};