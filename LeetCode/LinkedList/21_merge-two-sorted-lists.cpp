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
    ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
        
        ListNode* res=new ListNode();
    
        if(a==NULL && b==NULL)
            return NULL;
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;

        if(a->val <= b->val)
        {
            ListNode* newnode=new ListNode(); //(Node*)malloc(sizeof(Node));
            newnode->val=a->val;
            newnode->next=NULL;
            res=newnode;
            a=a->next;
        }
        else 
        {
            ListNode* newnode=new ListNode();
            newnode->val=b->val;
            newnode->next=NULL;
            res=newnode;
            b=b->next;
        }

        ListNode* current=res;

        while(a!=NULL && b!=NULL)
        {
            if(a->val <= b->val)
            {
                ListNode* newnode=new ListNode();
                newnode->val=a->val;
                newnode->next=NULL;
                current->next=newnode;
                current=current->next;
                a=a->next;
            }
            else {
                    ListNode* newnode=new ListNode();
                    newnode->val=b->val;
                    newnode->next=NULL;
                    current->next=newnode;
                    current=current->next;
                    b=b->next;
            }
        }

        while(a!=NULL)
        {
            ListNode* newnode=new ListNode();
            newnode->val=a->val;
            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
            a=a->next;
        }

        while(b!=NULL)
        {
            ListNode* newnode=new ListNode();
            newnode->val=b->val;
            newnode->next=NULL;
            current->next=newnode;
            current=current->next;
            b=b->next;
        }

        return res;
    }
};