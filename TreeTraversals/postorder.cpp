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

static int idx = -1;
Node* buildTree(vector<int>& preorder){

    idx++;

    if(preorder[idx] == -1){
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder);
    root->right = buildTree(preorder);

    return root;

}

void postOrderTraversal(vector<int>& preorder, Node* root){

    if(root == NULL) return;

    postOrderTraversal(preorder,root->left);
    postOrderTraversal(preorder,root->right);
    cout<<root->data<<" ";
}

int main(){

    vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    
    Node* root = buildTree(preorder);

    postOrderTraversal(preorder,root);
}