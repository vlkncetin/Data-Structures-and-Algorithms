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
    
    void printList(ListNode* head)
    {
        ListNode* current = head;
        
        while(current!=NULL)
        {
            cout<<current->val<<" ";
            current=current->next;
        }
        cout<<endl;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        if(left==right)
            return head;
        
        ListNode* leftList = head;
        ListNode* leftListCur = leftList;
        ListNode* middleList = NULL;
        ListNode* rightList = NULL;
        
        int i=1;
        if(left==1)
        {
            middleList=leftListCur;
            i--;
        }
        else
            while(leftListCur!=NULL)
            {
                if(i==left-1)
                {
                    middleList=leftListCur->next;
                    leftListCur->next=NULL;
                    break;
                }   
                i++;
                leftListCur=leftListCur->next;
            }
        
        ListNode* middleListCur = middleList;
        while(middleListCur!=NULL)
        {
            if(i==right-1)
            {
                rightList=middleListCur->next;
                middleListCur->next=NULL;
                break;
            }   
            i++;
            middleListCur=middleListCur->next;
        }
        
        middleList=reverseList(middleList);
        
        middleListCur = middleList;
        while(middleListCur->next!=NULL)
        {
            middleListCur=middleListCur->next;
        }
        middleListCur->next=rightList;
        
        if(left==1)
            return middleList;
        leftListCur->next=middleList;
                
        return leftList;
    }
};