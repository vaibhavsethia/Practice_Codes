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
    int preindex;
    TreeNode* buildtree(vector<int> &Pre, vector<int> &In, int Begin, int End, unordered_map<int,int> &Map){
        if(Begin > End){
          return NULL;
        }

        int Curr = Pre[preindex++];

        TreeNode *node = new TreeNode(Curr);

        if(Begin==End){
          return node;
        }
            
        int Index = Map[Curr];

        node->left=buildtree(Pre, In, Begin, Index-1, Map);
        node->right=buildtree(Pre, In, Index+1, End, Map);

        return node;
    }

    TreeNode* buildTree(vector<int>& Pre, vector<int>& In) {
        unordered_map <int,int> Map;
        preindex=0;

        for(int i=0; i<In.size(); i++){
            Map[In[i]]=i;
        }

        TreeNode *node = buildtree(Pre, In, 0, In.size()-1, Map);
        return node;
    }
   
};