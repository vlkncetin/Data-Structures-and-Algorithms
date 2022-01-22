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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res=NULL;
        ListNode* resHead=NULL;
        
        ListNode* cur1=l1;
        ListNode* cur2=l2;
        bool isFlag=false;
        while(cur1!=NULL || cur2!=NULL)
        {
            int sum=0;
            if(cur1==NULL)
                sum=cur2->val;
            if(cur2==NULL)
                sum=cur1->val;
            if(cur1!=NULL&&cur2!=NULL)
                sum=cur1->val+cur2->val;
                
            if(isFlag)
            {
                sum++;
            }
            
            if(sum>=10)
            {
                isFlag=true;
            }
            else
            {
                isFlag=false;
            }
            
            ListNode* temp=new ListNode(sum%10);
            
            if(res==NULL)
            {
                res=temp;
                resHead=res;
            }
            else
            {
                res->next=temp;
                res=res->next;
            }
            if(cur1!=NULL)
                cur1=cur1->next;
            if(cur2!=NULL)
                cur2=cur2->next;
        }
        
        if(isFlag)
        {
            ListNode* temp=new ListNode(1);
            res->next=temp;
        }

        return resHead;
    }
};