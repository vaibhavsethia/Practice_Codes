/*Complete the function below
Node is as follows
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

// root : the root Node of the given BST
// target : the target sum
unordered_map<int, int> Map;

void Inorder(Node *root){
    if(root == NULL){
        return;
    }
    
    Inorder(root->left);
    Map[root->data]++;
    Inorder(root->right);
}

int isPairPresent(struct Node *root, int target)
{
    Map.clear();
    int Sol = 0;
    Inorder(root);

    for(auto itr = Map.begin(); itr != Map.end(); itr++){
        auto Second = Map.find(abs(itr->first-target));
        if(Second != Map.end()){
            Sol += max(itr->second, Second->second);
        }
    }
    
    
    return Sol/2;
}