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
    Solution(ListNode* head) {
        m_head=head;
        
        ListNode* current=head;
        
        m_Lenght=0;
        while(current)
        {
            m_Lenght++;
            current=current->next;
        }
    }
    
    int getRandom() {
        int x=rand()%m_Lenght;
        
        ListNode* current=m_head;
        
        for(int i=0;i<=x;i++)
        {
            if(i==x)
                return current->val;
            current=current->next;
        }
        
        return -1;
    }

 private:
    ListNode* m_head;
    int m_Lenght;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */