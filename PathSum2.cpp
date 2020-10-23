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
    void pathSumUtil(TreeNode* root, int Sum, vector<vector<int>> &Sol, vector<int> Curr){
        if(!root){
          return;
        }

        Curr.push_back(root->val);

        if(root->val == Sum && root->left == NULL && root->right == NULL){
             Sol.push_back(Curr);
        }

        pathSumUtil(root->left, Sum - root->val, Sol, Curr);
        pathSumUtil(root->right, Sum - root->val, Sol, Curr); 
    }
    
     vector<vector<int>> pathSum(TreeNode* root, int Sum){
        vector<vector<int>> Sol;
        vector<int> Curr;
         
        if(!root){
            return {};
        }
         
        pathSumUtil(root, Sum, Sol, Curr);
        return Sol;
    }
    
};