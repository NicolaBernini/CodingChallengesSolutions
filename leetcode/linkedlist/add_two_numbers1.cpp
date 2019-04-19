
// Original Link 
// https://leetcode.com/problems/add-two-numbers/submissions/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


/**
  * @brief Solution 
  * 
  * @note There are 2 possible approaches 
  * 1) Convert the Linked List representation into an actual number representation (e.g. unsigned long int) and use the low level support for arithmetic then convert it back to Linked List 
  * 2) Implement the arithmetic to work directly on the Linked List representation 
  * The solution relies on this second approach as it is much more efficient 
  */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {     
        return list_sum(l1, l2); 
    }
    
    private:     
    ListNode* list_sum(const ListNode* a, const ListNode* b)
    {
        int t_res = a->val + b->val; 
        int r=t_res/10; 
        auto root = new ListNode(t_res%10); 
        auto last = root; 
        a = a->next; 
        b = b->next; 
        
        while((a != nullptr) || (b != nullptr))
        {
            int t_a=0; 
            int t_b=0; 
            
            if(a!=nullptr)
            {
                t_a = a->val; 
                a = a->next; 
            }
            
            if(b!=nullptr)
            {
                t_b = b->val; 
                b = b->next; 
            }
            int t_res = t_a+t_b+r; 
            r = t_res/10; 
            last->next = new ListNode(t_res%10); 
            last = last->next; 
        }
        if(r>0) last->next = new ListNode(r);
        
        return root; 
    }
    
};





