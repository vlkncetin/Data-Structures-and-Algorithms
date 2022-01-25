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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        vector<int> res{-1,-1};
        vector<int> localMaximaOrMinimaIndex;
        
        ListNode* current=head->next;
        ListNode* prev=head;
        int index=1;
        while(current->next!=NULL)
        {
            if(current->val>current->next->val && current->val>prev->val)
                localMaximaOrMinimaIndex.push_back(index);
            else if(current->val<current->next->val && current->val<prev->val)
                localMaximaOrMinimaIndex.push_back(index);
            index++;
            prev=current;
            current=current->next;
        }
        
        if(localMaximaOrMinimaIndex.size()>=2)
        {
            sort(localMaximaOrMinimaIndex.begin(),localMaximaOrMinimaIndex.end());
            int minimum=INT_MAX;
            for(int i=0;i<localMaximaOrMinimaIndex.size()-1;i++)
            {
                minimum=min(minimum, abs(localMaximaOrMinimaIndex[i+1]-localMaximaOrMinimaIndex[i]));
            }
            res[0]=minimum;
            res[1]=localMaximaOrMinimaIndex[localMaximaOrMinimaIndex.size()-1]-localMaximaOrMinimaIndex[0];
        }
        
        return res;
    }
};