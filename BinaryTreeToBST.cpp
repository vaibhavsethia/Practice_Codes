void Inorder(Node* root, vector<int> &A){
    if(!root){
        return;
    }
    
    Inorder(root->right, A);
    A.push_back(root->data);
    Inorder(root->left, A);
}

Node* ArrayToBST(vector<int> nums, int Low, int High){
    if(Low > High){
      return NULL;
    }
      
    int Mid = Low + (High-Low)/2;
    
    Node* root = new Node(nums[Mid]);
    
    root->left = ArrayToBST(nums , Low, Mid - 1);
    root->right = ArrayToBST(nums , Mid + 1 , High);
    
    return root;
}

Node *binaryTreeToBST (Node *root)
{
    if(!root){
        return root;
    }
    
    vector<int> A;
    Inorder(root, A);
    
    sort(A.begin(), A.end());
    
    return ArrayToBST(A, 0, A.size()-1);
}