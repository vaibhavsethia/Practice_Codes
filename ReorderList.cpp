Node* Rev(Node *head){
    Node *Curr = head;
    Node *Prev = NULL;
    Node *Next = NULL;
    
    while(Curr != NULL){
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
    }
    
    return Prev;
}

void reorderList(Node* head) { 
    Node* slow = head;
    Node* fast = slow->next; 
    
    while (fast && fast->next) { 
        slow = slow->next; 
        fast = fast->next->next; 
    } 
    
    Node* head1 = head; 
    Node* head2 = Rev(slow->next);
    slow->next = NULL; 
  
    head = newNode(0);
  
    Node* curr = head; 
    while (head1 || head2) { 
        if (head1) { 
            curr->next = head1; 
            curr = curr->next; 
            head1 = head1->next; 
        } 
  
        if (head2) { 
            curr->next = head2; 
            curr = curr->next; 
            head2 = head2->next; 
        } 
    } 
  
    head = head->next; 
} 