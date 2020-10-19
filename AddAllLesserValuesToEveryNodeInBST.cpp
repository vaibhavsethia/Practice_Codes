/*
Node structure is as follows:
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
void ModifyUtil(Node* root, int* Sum){
    if(!root){
        return;
    }
    
    ModifyUtil(root->left, Sum);
    
    *Sum += root->data;
    root->data = *Sum;
    
    ModifyUtil(root->right, Sum);
}

// modify the BST and return its root
Node* modify(Node *root)
{
    int Sum = 0;
    ModifyUtil(root, &Sum);
    return root;
}