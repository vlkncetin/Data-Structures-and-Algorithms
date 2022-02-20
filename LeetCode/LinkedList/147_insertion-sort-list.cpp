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
    void printList(ListNode* node)
    {
        while(node!=NULL)
        {
            cout<<node->val<<" ";
            node=node->next;
        }
        cout<<endl;
    }
    ListNode* insertionSortList(ListNode* head) {
        
        if(head->next==NULL)
            return head;
        
        int size=0;
        ListNode* curr=head;
        while(curr!=NULL)
        {
            size++;
            curr=curr->next;
        }
        
        ListNode* res=NULL;
        for(int i=0;i<size;i++)
        {
            if(res==NULL)
            {
                ListNode* tmp=new ListNode(head->val);
                res=tmp;
                head=head->next;
            }
            else
            {
                ListNode* tmp=new ListNode(head->val);
                if(head->val<=res->val)
                {
                    tmp->next=res;
                    res=tmp;
                    head=head->next;
                }
                else
                {
                    ListNode* curr=res;
                    ListNode* prev=NULL;
                    bool isFound=false;
                    while(curr!=NULL)
                    {
                        if(head->val<=curr->val && head->val>=prev->val)
                        {
                            isFound=true;
                            if(prev==NULL)
                            {
                                tmp->next=res;
                                res=tmp;
                            }
                            else
                            {
                                prev->next=tmp;
                                tmp->next=curr;
                            }
                            
                            break;
                        }
                        prev=curr;
                        curr=curr->next;
                    }
                    
                    if(!isFound)
                    {
                        prev->next=tmp;
                    }
                    head=head->next;
                }
            }
        }
        
        return res;
    }
};