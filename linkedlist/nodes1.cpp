
// Solution for 
// https://www.hackerrank.com/challenges/delete-a-node-from-a-linked-list/problem
// Complete the deleteNode function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* deleteNode(SinglyLinkedListNode* head, int position) 
{    
    SinglyLinkedListNode* prev = NULL; 
    SinglyLinkedListNode* pos = head; 
    while(position > 0)
    {
        prev = pos; 
        pos = pos->next; 
        position--;
    }
    
    if(prev == NULL)
    {
        // Head Changes 
        pos = pos->next; 
        delete head; 
        return pos; 
    }
    
    prev->next = pos->next; 
    delete pos; 
    return head; 
}

