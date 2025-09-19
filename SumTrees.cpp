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
void preorderT(Node* root){
    if(root == NULL) return;

    cout<<root->data<<" ";
    preorderT(root->left);
    preorderT(root->right);
}

int sumTree(Node* root){

    if(root == NULL){
        return 0;
    }

    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);

    root->data = leftSum + rightSum + root->data;

    return root->data;
}

int main(){

    vector<int>preorder = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    Node* root = buildTree(preorder);

    cout<<"preorder before conversion: ";
    preorderT(root);

    int sum = sumTree(root);

    cout<<endl;
    cout<<"preorder after conversion: ";
    preorderT(root);

    cout<<"final root Sum: "<<sum;
}