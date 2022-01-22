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
    ListNode* reverseList(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        ListNode* newfirst=head;
        ListNode* afterLastNode=NULL;
        ListNode* lastNode=head;

        while(lastNode->next!=NULL)
        {
            lastNode=lastNode->next;
        }
        // 1->2->3->4->5->null => 5->4->3->2->1->null
        // 17->15->8->12->10->5->4->1->7->6->NULL
        while(newfirst!=lastNode)
        {
            if(lastNode->next==NULL)
            {
                newfirst=newfirst->next;
                ListNode* temp=head;
                temp->next=NULL;
                lastNode->next=temp;
                afterLastNode=temp;
            }
            else
            {
                newfirst=newfirst->next;
                ListNode* temp=head;
                temp->next=afterLastNode;
                lastNode->next=temp;
                afterLastNode=temp;
            }
            head=newfirst;
        } 
        return head;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* res=NULL;
        ListNode* resHead=NULL;
        
        l1=reverseList(l1);
        l2=reverseList(l2);
        
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

        return reverseList(resHead);
    }
};