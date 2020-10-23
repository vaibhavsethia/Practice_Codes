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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void Inorder(TreeNode* root, vector<vector<int>> *Sol, int Level) {
      if (root == NULL) {
          return;
      }
      if (Level == Sol->size()) {
          Sol->push_back({});
      }                
      Inorder(root->left, Sol, Level+1);
      Sol->at(Level).push_back(root->val);
      Inorder(root->right, Sol, Level+1);        
  }
    
  vector<vector<int>> levelOrder(TreeNode* root) {
      vector<vector<int>> Sol;
      Inorder(root, &Sol, 0);
      return Sol;
  }
};