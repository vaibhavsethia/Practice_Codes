Node* newNode(int data) 
{ 
    Node* new_node = new Node(data); 
    return new_node; 
}

Node* reverseList(Node* head) {
    Node* Curr = head;
    Node* Prev = NULL;
    Node* Next;
        
    while(Curr !=NULL){
        Next = Curr->next;
        Curr->next = Prev;
        Prev = Curr;
        Curr = Next;
    }
    
    return Prev;
}

struct Node* addTwoLists(struct Node* first, struct Node* second)
{
    if(first == NULL){
        return second;
    }
    
    if(second == NULL){
        return first;
    }
    
    Node *Temp = first;
    int M = 0, N = 0;
    
    while(Temp != NULL){
        Temp = Temp->next;
        M++;
    }
    
    Temp = second;
    
    while(Temp != NULL){
        Temp = Temp->next;
        N++;
    }
    
    first = reverseList(first);
    second = reverseList(second);
    
    Node* Res = NULL; 
    Node* Prev = NULL; 
    int Carry = 0, Sum; 
  
    while (first != NULL || second != NULL) { 
        Sum = Carry + (first ? first->data : 0) + (second ? second->data : 0); 
        Carry = (Sum >= 10) ? 1 : 0; 
        Sum = Sum % 10; 
        Temp = newNode(Sum); 
        
        if (Res == NULL) {
            Res = Temp;
        } else{
            Prev->next = Temp;
        }
             
        Prev = Temp; 
        
        if (first){
            first = first->next;
        }
        if (second){
            second = second->next;
        }
    } 
  
    if (Carry > 0) 
        Temp->next = newNode(Carry); 
    return reverseList(Res); 
}