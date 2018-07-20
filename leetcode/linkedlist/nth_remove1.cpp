
// Solution to 
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

#include <vector>
using namespace std; 

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// This can be used to remove all intermediate nodes hence not the root and not the last one 
void removeNextNode(ListNode* node)
{
    auto tbd = node->next; 
    node->next = node->next->next; 
    free(tbd); 
}

vector<ListNode*> explore(ListNode* root)
{
    vector<ListNode*> res; 
    while(root!=nullptr) 
    {
        res.push_back(root); 
        root = root->next; 
    }

    return res;
}

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        auto list = explore(head); 
        if(n == list.size())
        {
            // remove_head 
            auto new_head = head->next; 
            free(head); 
            return new_head; 
        }
        if(n == 1)
        {
            // remove_tail 
            list[list.size()-2]->next = nullptr; 
            free(list[list.size()-1]); 
        }
        else removeNextNode(list[list.size()-n-1]); 
        return head; 
        
    }
};

