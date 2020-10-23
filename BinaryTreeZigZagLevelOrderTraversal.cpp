/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };knf
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
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> Sol;
        Inorder(root, &Sol, 0);
        
        for(int i=0; i<Sol.size(); i++){
            if(i%2 != 0){
                reverse(Sol[i].begin(), Sol[i].end());
            }
        }
        return Sol;   
    }
};


