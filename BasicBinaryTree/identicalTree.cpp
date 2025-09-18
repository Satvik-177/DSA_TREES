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

Node* buildTree(vector<int>& preorder, int& idx){

    idx++;

    if(preorder[idx] == -1){
        return NULL;
    }

    Node* root = new Node(preorder[idx]);
    root->left = buildTree(preorder,idx);
    root->right = buildTree(preorder,idx);

    return root;
}

bool isIdentical(Node* root1, Node* root2){

    if(root1 == NULL || root2 == NULL){
        return root1 == root2;
    }

    bool leftSame = isIdentical(root1->left,root2->left);
    bool rightSame = isIdentical(root1->right,root2->right);

    return leftSame && rightSame && root1->data == root2->data;
}

int main(){

    vector<int>preorder1 = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    vector<int>preorder2 = {1,2,-1,-1,-1,4,-1,-1,5,-1,-1};
    
    int idx1 = -1, idx2 = -1;
    Node* root1 = buildTree(preorder1,idx1);
    Node* root2 = buildTree(preorder2,idx2);

    if(isIdentical(root1,root2)){
        cout<<"Yes, Identical";
    }
    else{
        cout<<"not identical";
    }
    
}