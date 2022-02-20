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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        vector<int> vec;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            if(curr->val!=0)
                vec.push_back(curr->val);
            curr=curr->next;
        }
        
        
        for (int i=0;i<vec.size();i++)
        {
            int sum=0,j=0;
            for(j=i;j<vec.size();j++)
            {
                sum += vec[j];
                if(sum==0)
                    break;
            }            
            if(sum==0)
            {
                vec.erase(vec.begin()+i,vec.begin()+j+1);
                i=-1;
            }
        }
        
        ListNode* res=NULL;
        curr=NULL;
        
        for (int i=0;i<vec.size();i++)
        {
            ListNode* tmp=new ListNode(vec[i]);
            if(res==NULL)
            {
                res=tmp;
                curr=res;
            }
            else
            {
                curr->next=tmp;
                curr=curr->next;
            }
        }
        
        return res;
    }
};