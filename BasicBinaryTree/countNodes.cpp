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

int cnt_Nodes(Node* root){

    if(root == NULL) return 0;

    int leftNodeCount = cnt_Nodes(root->left);
    int rightNodeCount = cnt_Nodes(root->right);

    return leftNodeCount+rightNodeCount+1;
}

int main(){

    vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    
    Node* root = buildTree(preorder);

    int totalNodes = cnt_Nodes(root);

    cout<<"Total Nodes in this binary tree: "<<totalNodes;
}