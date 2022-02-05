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
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while(curr)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(head==NULL)
            return NULL;
        
        vector<ListNode*> reversedLists;
        ListNode* curr=head;
        int lenght=0;
        
        while(curr)
        {
            lenght++;
            curr=curr->next;
        }
        
        curr=head;
        int counter=1;
        ListNode* headOfSplit=head;
        
        while(curr)
        {
            if(counter==k)
            {
                ListNode* temp=curr->next;
                curr->next=NULL;
             
                reversedLists.push_back(reverse(headOfSplit));
                
                curr=temp;
                headOfSplit=curr;
                counter=1;
             
                continue;
            }
                
            counter++;
            curr=curr->next;
        }
        
        if(headOfSplit!=NULL)
            reversedLists.push_back(headOfSplit);
        
        ListNode* resultList=reversedLists[0];
        curr=resultList;
        for(int i=1;i<reversedLists.size();i++)
        {
            while(curr->next)
            {
                curr=curr->next;
            }
            curr->next=reversedLists[i];
        }
        
        
        return resultList;
    }
};