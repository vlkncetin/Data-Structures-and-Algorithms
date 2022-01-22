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
    ListNode* oddEvenList(ListNode* head) {
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        
        ListNode* current=head;
        ListNode* newlist=NULL;
        ListNode* current2=newlist;
        
        int x=0;
        while(current!=NULL)
        {
            if(x%2==0)
            {
                ListNode* newnode=new ListNode(current->val);
                if(newlist==NULL)
                {
                    newlist=newnode;
                    current2=newlist;
                }
                else
                {
                    current2->next=newnode;
                    current2=current2->next;
                }
            }
            x++;
            current=current->next;
        }
        
        current=head;
        
        x=0;
        while(current!=NULL)
        {
            if(x%2==1)
            {
                ListNode* newnode=new ListNode(current->val);
                current2->next=newnode;
                current2=current2->next;
            }
            x++;
            current=current->next;
        }
        
        return newlist;
    }
};