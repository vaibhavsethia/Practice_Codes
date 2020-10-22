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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0){
          return NULL;
        }
            
        return sortedArrayToBSTUtil(nums, 0, nums.size()-1);
        
    }
    
    TreeNode* sortedArrayToBSTUtil(vector<int>& nums, int Low , int High)
    {
        if(Low > High){
          return NULL;
        }
          
        int Mid = Low + (High-Low)/2;
        
        TreeNode* root = new TreeNode(nums[Mid]);
        
        root->left=sortedArrayToBSTUtil(nums , Low, Mid - 1);
        root->right=sortedArrayToBSTUtil(nums , Mid + 1 , High);
        
        return root;
    }
};