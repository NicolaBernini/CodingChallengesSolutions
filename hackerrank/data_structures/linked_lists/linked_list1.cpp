// Solution to 
// https://www.hackerrank.com/challenges/print-the-elements-of-a-linked-list

/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
void Print(Node *in_wire_head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    while(in_wire_head != NULL) {printf("%d\n", in_wire_head->data); in_wire_head = in_wire_head->next;}
}


