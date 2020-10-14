/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

void FindDistances(Node *node, int *Min, int *Max, int HorizontalDistance) 
{ 
    if (node == NULL) return; 
  
    if (HorizontalDistance < *Min)  *Min = HorizontalDistance; 
    else if (HorizontalDistance > *Max) *Max = HorizontalDistance; 
  
    FindDistances(node->left, Min, Max, HorizontalDistance-1); 
    FindDistances(node->right, Min, Max, HorizontalDistance+1); 
} 

void printLine(Node *node, int LineNo, int HorizontalDistance) 
{ 
    if (node == NULL) return; 
  
    if (HorizontalDistance == LineNo) 
        cout << node->data << " "; 
  
    printLine(node->left, LineNo, HorizontalDistance-1); 
    printLine(node->right, LineNo, HorizontalDistance+1); 
}

void verticalOrder(Node *root) 
{ 
    int Min = 0, Max = 0; 
    FindDistances(root, &Min, &Max, 0); 
  
    for (int LineNo = Min; LineNo <= Max; LineNo++) 
    { 
        printLine(root, LineNo, 0); 
        cout << endl; 
    } 
}