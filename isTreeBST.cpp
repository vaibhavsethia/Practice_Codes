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

bool isBSTCheck(Node* root, int Min, int Max){
    if(root == NULL){
        return true;
    }
    
    if(root->data < Min || root->data > Max){
        return false;
    }
    
    return isBSTCheck(root->left, Min, root->data-1) && isBSTCheck(root->right, root->data+1, Max);
}

// return true if the given tree is a BST, else return false
bool isBST(Node* root) {
    return isBSTCheck(root, INT_MIN, INT_MAX);
}