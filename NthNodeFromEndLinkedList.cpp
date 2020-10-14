/* struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

/* Should return data of n'th node from the end of linked list.
*  head: head of the linked list
*  n: nth node from end to find
*/
int getNthFromLast(Node *head, int n)
{
    int Len = 0;
    Node* Temp = head;
    while(Temp){
        Temp = Temp->next;
        Len++;
    }
    
    if(Len < n){
        return -1;
    } else if(Len == n){
        return head->data;
    }
    
    for(int i=1; i<=Len-n; i++){
        head = head->next;
    }
    
    return head->data;
}