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
    
    ModifyUtil(root->right, Sum);
    
    *Sum += root->data;
    root->data = *Sum;
    
    ModifyUtil(root->left, Sum);
}

// modify the BST and return its root
Node* modify(Node *root)
{
    int Sum = 0;
    ModifyUtil(root, &Sum);
    return root;
}

// Node* modify(Node *root)
// {
//     A.clear();
//     Inorder(root);
    
//     for(int i=1; i<A.size(); i++){
//         A[i] += A[i-1];
//     }
    
//     reverse(A.begin(), A.end());
    
//     for(int i=0; i<A.size(); i++){
//         cout<<A[i]<<" ";
//     }
//     return NULL;
// }

