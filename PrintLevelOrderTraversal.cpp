int Height(TreeNode* root) {
    if(!root){
        return 0;
    }
    
    return max(Height(root->left) + 1,Height(root->right) + 1);
}

void printGivenLevel(node* root, int level){  
    if (root == NULL){
      return; 
    }
         
    if (level == 1){
      cout << root->data << " "; 
    } else if (level > 1){  
        printGivenLevel(root->left, level-1);  
        printGivenLevel(root->right, level-1);  
    }  
}  

void printLevelOrder(node* root)  
{  
    int h = Height(root);  
    int i;  
    for (i = 1; i <= h; i++){
      printGivenLevel(root, i); 
    }
         
} 