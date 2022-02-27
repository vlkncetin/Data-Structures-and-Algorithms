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
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr=head;
        ListNode* prev=NULL;
        
        while(curr!=NULL)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        
        ListNode* curr=head;
        ListNode* prev=NULL;
        int nodeCount=1;
        
        while(curr!=NULL)
        {
            if(nodeCount%2==0)
            {
                ListNode* subHead=curr;
                ListNode* curr2=subHead;
                int counter=1;
                for(int i=0;i<nodeCount-1 && curr2!=NULL ;i++)
                {
                    curr2=curr2->next;
                    counter++;
                }
                ListNode* next=NULL;
                if(curr2!=NULL)
                {
                    next=curr2->next;
                    curr2->next=NULL;
                }
                else if(curr2==NULL && counter%2==0)
                {
                    return head;
                }
                
                subHead=reverse(subHead);
                
                prev->next=subHead;
                
                curr2=subHead;
                for(int i=0;i<nodeCount-1 && curr2!=NULL ;i++)
                {
                    curr2=curr2->next;
                }
                if(curr2!=NULL)
                    curr2->next=next;
                prev=curr2;
                curr=next;
            }
            else
            {
                ListNode* subHead=curr;
                ListNode* curr2=subHead;
                int i=0;
                while(curr2!=NULL)
                {
                    i++;
                    curr2=curr2->next;
                }
                if(curr2==NULL && i<nodeCount && i%2==0)
                {
                    subHead=reverse(subHead);
                    prev->next=subHead;
                    return head;
                }
                else
                {
                    for(int i=0;i<nodeCount && curr!=NULL ;i++)
                    {
                        prev=curr;
                        curr=curr->next;
                    }
                }
                
            }
            
            nodeCount++;
        }
        
        return head;
    }
};