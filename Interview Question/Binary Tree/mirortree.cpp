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

   void invertTreeHelper(Node* node) {
        if (!node) {
            return;
        }
       
        invertTreeHelper(node->left);
        invertTreeHelper(node->right);
         Node* tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
    Node* invertTree(Node* root) {
        if (!root) {
            return root;
        }
        invertTreeHelper(root);
        return root;
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
   invertTree(root);
   inorder(root);
}