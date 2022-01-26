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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> res;
        
        int len=0;
        ListNode* current=head;
        
        //get lenght
        while(current)
        {
            len++;
            current=current->next;
        }
        
        //maximum size of a split part
        int maxPartSize=1;
            
        if(k<len)
        {
            //calculate the maximum size of a split
            maxPartSize=len/k;
            if(len%k!=0)
                maxPartSize++;
        }
        else
        {
            //if k is bigger than linked list size, then fill the vector one node by one node
            current=head;
            for(int i=0;i<k;i++)
            {
                if(current)
                {
                    ListNode* temp=current->next;
                    current->next=NULL;
                    res.push_back(current);
                    current=temp;
                }
                else
                {
                    ListNode* temp=NULL;
                    res.push_back(temp);
                }
            }
            
            //exit with result
            return res;
        }
        
        //if the linked list lenght is bigger than k.
        current=head;
        ListNode* headOfPart=head;
        int currentPartSize=1;
        
        while(current)
        {
            if(currentPartSize==maxPartSize)
            {
                currentPartSize=1;
                ListNode* temp=current->next;
                current->next=NULL;
                res.push_back(headOfPart);
                headOfPart=temp;
                current=temp;
                        
                //recalculate new max split part size of the remaining list
                if(k-1<=len-maxPartSize)
                {
                    k=k-1;
                    if(k==0)
                        break;
                    len=len-maxPartSize;
                    maxPartSize=len/k;
                    
                    if(len%k!=0)
                        maxPartSize++;
                }
            }
            else
            {
                currentPartSize++;
                current=current->next;
            }
        }
            
        return res;
    }
};