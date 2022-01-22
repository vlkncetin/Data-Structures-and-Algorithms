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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current=head;
        ListNode* prev=NULL;
        ListNode* newlist=NULL;
        ListNode* current2=newlist;
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        
        while(current->next!=NULL)
        {
            if(prev==NULL)
            {
                if(current->val!=current->next->val)
                {
                    ListNode* temp=new ListNode(current->val);
                    newlist=temp;  
                    current2=newlist;
                }
            }
            else if(prev&&(current->val!=current->next->val)&&(current->val!=prev->val))
            {
                
                if(newlist==NULL)
                {
                    ListNode* temp=new ListNode(current->val);
                    newlist=temp;  
                    current2=newlist;
                    
                }
                 else
                 {
                    ListNode* temp=new ListNode(current->val);
                    current2->next=temp; 
                    current2=current2->next;
                 }
                
            }
            
            prev=current;
            current=current->next;
        }
        
        if(prev->val != current->val)
        {
            if(newlist==NULL)
            {
                ListNode* temp=new ListNode(current->val);
                newlist=temp;  
                current2=newlist;

            }
            else{
                ListNode* temp=new ListNode(current->val);
                current2->next=temp;  
             }
            
        }
        return newlist;
    }
};