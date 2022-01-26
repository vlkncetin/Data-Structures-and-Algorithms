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
    vector<int> nextLargerNodes(ListNode* head) {
        
        ListNode* current=head;
        ListNode* current2=head;
        
        vector<int> res;
        
        while(current!=NULL)
        {
            current2=current;
            int nextGreater=0;
            while(current2!=NULL)
            {
                if(current2->val>current->val)
                {
                    nextGreater=current2->val;
                    break;
                }
                current2=current2->next;
            }
            res.push_back(nextGreater);
            current=current->next;
        }
        
        return res;
    } 
};