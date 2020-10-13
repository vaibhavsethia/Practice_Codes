//User function Template for C++
/*Structure of the node of the binary tree is as
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

int Height(Node* root){
    if(root == NULL){
        return 0;
    }
    
    int LH = Height(root->left);
    int RH = Height(root->right);
    
    return LH>RH?LH+1:RH+1;
}

void LevelPrint(Node* root, int Level, int flag){
    if (root == NULL)  
        return;  
        
    if (Level == 1)  
        cout << root->data << " "; 
        
    else if (Level > 1)  
    {  
        if(flag){
            LevelPrint(root->left, Level-1, flag);  
            LevelPrint(root->right, Level-1, flag);  
        } else{
            LevelPrint(root->right, Level-1, flag);  
            LevelPrint(root->left, Level-1, flag); 
        }
    }
}

// return a vector containing the zig zag level order traversal of the given tree
vector <int> zigZagTraversal(Node* root)
{
    vector<int> Sol;
    
    bool flag = true;
    
	for(int i=1; i<=Height(root); i++){
	    LevelPrint(root, i, flag);
	    flag = !flag;
	}
	
	return Sol;
}