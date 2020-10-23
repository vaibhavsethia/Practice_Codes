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
    int postIndex;
    TreeNode* buildtree(vector<int> &Post, vector<int> &In, int Begin, int End, unordered_map<int,int> &Map){
        if(Begin > End){
          return NULL;
        }

        int Curr = Post[postIndex++];

        TreeNode *node = new TreeNode(Curr);

        if(Begin==End){
          return node;
        }
            
        int Index = Map[Curr];

        node->left=buildtree(Post, In, Begin, Index-1, Map);
        node->right=buildtree(Post, In, Index+1, End, Map);

        return node;
    }
    
    TreeNode* buildTree(vector<int>& In, vector<int>& Post) {
        unordered_map <int,int> Map;
        postIndex = 0;

        for(int i=0; i<In.size(); i++){
            Map[In[i]]=i;
        }

        TreeNode *node = buildtree(Post, In, 0, In.size()-1, Map);
        return node;
    }
};