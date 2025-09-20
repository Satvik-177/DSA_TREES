#include<bits/stdc++.h>
using namespace std;

class Node{

    public: int data;
    public: Node* left;
    public: Node* right;

    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void inorder(Node* root){

    if(root == NULL) return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* insert(Node* root, int val){
    
    if(root == NULL){
        return new Node(val);
    }

    if(root->data > val){
        root->left = insert(root->left,val);
    }
    else{
        root->right = insert(root->right,val);
    }

    return root;
}

Node* buildBST(vector<int>& arr){

    Node* root = NULL;

    for(int val:arr){
       root = insert(root,val);
    }

    return root;
}

int main(){

    vector<int>arr = {3,2,1,5,6,4};

    Node* root = buildBST(arr);

    inorder(root);
}