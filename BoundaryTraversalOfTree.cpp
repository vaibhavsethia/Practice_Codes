#include<bits/stdc++.h>
using namespace std;
  
struct Node{ 
    int data; 
    Node *left, *right; 
}; 
  
void BottomBoundary(Node* root){ 
    if (root == NULL){
        return;
    } 
  
    BottomBoundary(root->left); 
  
    if (!(root->left) && !(root->right)) 
        cout<<root->data<<" ";
  
    BottomBoundary(root->right); 
} 

void LeftBoundary(Node* root){ 
    if (root == NULL){
        return;
    } 
  
    if (root->left){
        cout<<root->data<<" ";
        LeftBoundary(root->left); 
    }else if (root->right){ 
        cout<<root->data<<" ";
        LeftBoundary(root->right); 
    }
} 

void RightBoundary(Node* root){ 
    if (root == NULL){
        return;
    } 
  
    if (root->right){ 
        RightBoundary(root->right); 
        cout<<root->data<<" ";
    } else if (root->left){ 
        RightBoundary(root->left); 
        cout<<root->data<<" ";
    } 
} 
  
void printBoundary(Node* root){ 
    if (root == NULL){
        return;
    } 
  
    cout<<root->data<<" ";
  
    LeftBoundary(root->left); 
    BottomBoundary(root->left); 
    BottomBoundary(root->right); 
    RightBoundary(root->right); 
} 
  
Node* NewNode(int Value){ 
    Node* Temp = new Node; 

    Temp->data = Value; 
    Temp->left = Temp->right = NULL; 
  
    return Temp; 
} 
  
int main(){ 
    Node* root = NewNode(21); 
    root->left = NewNode(8); 
    root->left->left = NewNode(4); 
    root->left->right = NewNode(12); 
    root->left->right->left = NewNode(10); 
    root->left->right->right = NewNode(14); 
    root->right = NewNode(22); 
    root->right->right = NewNode(25); 
  
    printBoundary(root); 
  
    return 0; 
} 