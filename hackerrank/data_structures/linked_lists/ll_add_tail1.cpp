// Solution regarding 
// https://www.hackerrank.com/challenges/insert-a-node-at-the-tail-of-a-linked-list/problem

/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

// node = map(p_build_node, [constr args])
Node* do_node_build(const int data, Node* next)
{
    Node* node=new Node; 
    node->data=data; 
    node->next=next; 
    return node; 
}

Node* Insert(Node *head,int data)
{
  // Complete this method
  Node* t_head=head; 
  if(head==NULL) return do_node_build(data, NULL); 
  // node_ref = map(p_list_nav, list, end)
  while(head->next!=NULL) head=head->next; 
  // node_tail = map(p_add_node, node_ref, val)
  head->next=do_node_build(data, NULL); 
  return t_head; 
}
