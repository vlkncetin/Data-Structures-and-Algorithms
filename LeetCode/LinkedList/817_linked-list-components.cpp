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
    int numComponents(ListNode* head, vector<int>& nums) {
        
        int count=0;
        
        ListNode* current=head;
        
        bool isSearchingForNew=true;
        while(current!=NULL)
        {
            if(isSearchingForNew)
            {
                if(find(nums.begin(),nums.end(),current->val)==nums.end())
                {
                    current=current->next;
                    continue;
                }
                count++;
                isSearchingForNew=false;
            }
            else
            {
                if(find(nums.begin(),nums.end(),current->val)==nums.end())
                {
                    isSearchingForNew=true;
                    current=current->next;
                    continue;
                } 
            }
            current=current->next;
        }
        
        return count;
    }
};