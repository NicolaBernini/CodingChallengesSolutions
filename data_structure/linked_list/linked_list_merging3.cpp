
// Solution for 
// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem

// Complete the mergeLists function below.

void fix(SinglyLinkedListNode* head, SinglyLinkedListNode* other) 
{
    SinglyLinkedListNode* other_stop=nullptr; 
    SinglyLinkedListNode* temp=nullptr; 
    
    if(head==nullptr) {cout << "UNEXPECTED" << endl; return;}
    if(other==nullptr) return; 
    cout << "Checking head=" << head->data << ", other=" << other-> data << endl; 
    if(head->next == nullptr) {head->next = other; return;}
    if(head->next->data < other->data) fix(head->next, other); 
    else 
    {
        // Insert 
        other_stop = other; 
        while((other_stop->data < head->next->data) && (other_stop->next!=nullptr)) other_stop = other_stop->next; 
        temp = other_stop->next; 
        other_stop->next = head->next; 
        head->next = other; 
        other=temp; 
        //if(other == nullptr) return; 
        fix(head, other); 
    }
}

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) 
{
    SinglyLinkedListNode* head=nullptr; 
    SinglyLinkedListNode* other=nullptr; 
    
    if(head1->data <= head2->data) 
    {
        head=head1; 
        other=head2; 
    }
    else 
    {
        head=head2; 
        other=head1; 
    }
    
    fix(head, other); 
    
    return head; 
}

