#include<iostream>
#include<vector>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void inorder(Node* root){
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}


int maximum_depth(Node* root){
    if (root==NULL)
    {
        return 0;
    }
    int lheight=maximum_depth(root->left);
    int rheight=maximum_depth(root->right);
    return max(lheight,rheight)+1;

}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    // inorder print
    inorder(root);
    cout<<endl;
    cout<<maximum_depth(root)<<" ";
    return 0;
}