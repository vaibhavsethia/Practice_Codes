int largestBSTUtil(Node* root, int *Min, int *Max, int *MaxSize, bool *IsBST){  
    if(root == NULL){  
        *IsBST = 1;
        return 0;
    }
      
    int min = INT_MAX;  
    bool left_flag = false;  
    bool right_flag = false;  
    int LeftSubtree, RightSubtree;

    *Max = INT_MIN;  
    LeftSubtree = largestBSTUtil(root->left, Min, Max, MaxSize, IsBST);  

    if(*IsBST == 1 && root->data > *Max){
      left_flag = true;
    }
        
    min = *Min;  
      
    *Min = INT_MAX;  
    RightSubtree = largestBSTUtil(root->right, Min, Max, MaxSize, IsBST); 

    if(*IsBST == 1 && root->data < *Min){
      right_flag = true;  
    }

    if(min < *Min){
      *Min = min;  
    }
    if (root->data < *Min){
      *Min = root->data; 
    } 
    if (root->data > *Max){
      *Max = root->data;
    } 

    if(left_flag && right_flag){  
        if (LeftSubtree + RightSubtree + 1 > *MaxSize){
          *MaxSize = LeftSubtree + RightSubtree + 1;  
        }
            
        return LeftSubtree + RightSubtree + 1;  
    } else {  
        *IsBST = 0;  
        return 0;  
    }  
}  

int largestBST(Node* root){   
  int Min = INT_MAX, Max = INT_MIN, MaxSize = 0;  
  bool IsBST = false;  
    
  largestBSTUtil(root, &Min, &Max, &MaxSize, &IsBST);  
    
  return MaxSize;  
}