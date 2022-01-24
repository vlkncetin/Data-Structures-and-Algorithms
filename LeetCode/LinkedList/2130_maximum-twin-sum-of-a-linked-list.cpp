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
    void printList(ListNode* head)
    {
        ListNode* current=head;
        while(current!=NULL)
        {
            cout<<current->val<<" ";
            current=current->next;
        }
        cout<<endl;
    }
    ListNode* reverseList(ListNode* head) {
        
        ListNode* res=head;
        if(res==NULL)
            return NULL;
        if(res->next==NULL)
            return res;
        ListNode* newfirst=res;
        ListNode* afterLastNode=NULL;
        ListNode* lastNode=res;

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
                ListNode* temp=res;
                temp->next=NULL;
                lastNode->next=temp;
                afterLastNode=temp;
            }
            else
            {
                newfirst=newfirst->next;
                ListNode* temp=res;
                temp->next=afterLastNode;
                lastNode->next=temp;
                afterLastNode=temp;
            }
            res=newfirst;
        } 
        return res;
    }
    
    int pairSum(ListNode* head) {
        
        ListNode* slow=head;
        ListNode* fast=head;
        int ans=INT_MIN;

        while(fast!=NULL)
        {
            slow=slow->next;
            if(fast->next!=NULL)
                 fast=fast->next->next;
            else
                break;
        }
        
        slow=reverseList(slow);
        
        while(slow)
        {
            ans=max(ans,slow->val+head->val);
            slow=slow->next;
            head=head->next;
        }
        return ans;
    }
};