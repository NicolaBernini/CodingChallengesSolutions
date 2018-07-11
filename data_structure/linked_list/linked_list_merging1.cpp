
// Solution to 
// https://www.hackerrank.com/challenges/merge-two-sorted-linked-lists/problem

// Complete the mergeLists function below.

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
    // Note: Just temporary init
    SinglyLinkedListNode* init_head=nullptr; 
    SinglyLinkedListNode* head=nullptr; 
    SinglyLinkedListNode* other=nullptr; 
    SinglyLinkedListNode* other_stop=nullptr; 
    SinglyLinkedListNode* temp=nullptr; 
    
    
    
    if(head1->data <= head2->data) 
    {
        init_head = head1; 
        head=head1; 
        other=head2; 
    }
    else 
    {
        init_head=head2; 
        head=head2; 
        other=head1; 
    }

    while( (head->next != nullptr) && (other->next != nullptr) )
    {
        if(head->next->data < other->data) head = head->next; 
        else 
        {
            // Insert 
            other_stop = other; 
            while((other_stop->data < head->next->data) && (other_stop->next!=nullptr)) other_stop = other_stop->next; 
            temp = other_stop->next; 
            other_stop->next = head->next; 
            head->next = other; 
            other=temp; 
            if(other == nullptr) break; 
        }
    }
    if(other != nullptr)
    {
        // Attach the final part to the end of the list 
        //cout << "Final head=" << head->data << ", other=" << other->data << endl; 
        while(head->next!=nullptr) head=head->next; 
        head->next=other;             
    }
    
    return init_head; 
}

