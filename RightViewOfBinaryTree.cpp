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
    
    vector<int> Sol;
    
    void RightViewUtil(TreeNode* root, int Level, int* MaxLevel){
        if(!root){
            return;
        }
        
        if(*MaxLevel < Level){
            Sol.push_back(root->val);
            *MaxLevel = Level;
        }
        
        RightViewUtil(root->right, Level+1, MaxLevel);
        RightViewUtil(root->left, Level+1, MaxLevel);
    }
    
    vector<int> rightSideView(TreeNode* root) {
       int Max = 0;
        Sol.clear();
        RightViewUtil(root, 1, &Max);
        return Sol;  
    }
};