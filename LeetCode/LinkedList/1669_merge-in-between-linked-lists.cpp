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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        
        int index=0;
        ListNode* current=list1;
        ListNode* prev;
        
        ListNode* prevOfFirstRemoved;
        ListNode* lastRemoved;
        
        while(current!=NULL)
        {
            if(index==a)
            {
                prevOfFirstRemoved=prev;
            }
            if(index==b)
            {
                lastRemoved=current;
                break;
            }
            prev=current;
            current=current->next;
            index++;
        }
        
        ListNode* current2=list2;
        
        while(current2->next!=NULL)
        {
            current2=current2->next;
        }
        
        current2->next=current->next;
        prevOfFirstRemoved->next=list2;
        lastRemoved->next=NULL;
        
        return list1;
    }
};