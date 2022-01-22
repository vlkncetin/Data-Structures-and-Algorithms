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
    bool isPalindrome(ListNode* head) {
        bool isPalin=true;
    
        ListNode* current=head;

        vector<int> values;
        while(current!=NULL)
        {
            values.push_back(current->val);
            current=current->next;
        }

        for(int i=0;i<values.size()/2;i++)
        {
            if(values[i]!=values[values.size()-i-1])
                return false;
        }

        return isPalin;
    }
};