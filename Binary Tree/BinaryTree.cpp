#include<iostream>
using namespace std;

struct BinaryTree
{
    /* data */
    int data;
    struct BinaryTree*left;
    struct BinaryTree*right;

    BinaryTree(int val)
    {
        data=val;
        left=NULL;
        right=NULL;
    }
};


// preorder Traversal
void Preorder(struct BinaryTree*root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

// Inorder Traversal

void Inorder(struct BinaryTree*root){
    if (root==NULL)
    {
        return;
    }
   
    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}

// Postorder Traversal

void Postorder(struct BinaryTree*root){
    if (root==NULL)
    {
        return;
    }
   
    Postorder(root->left);
  
    Postorder(root->right);
    cout<<root->data<<" ";
}


int main(){
    struct BinaryTree* root=new BinaryTree(1);
    root->left=new BinaryTree(2);
    root->right=new BinaryTree(3);
    root->left->left=new BinaryTree(4);
    root->left->right=new BinaryTree(5);
    root->right->left=new BinaryTree(6);
    root->right->right=new BinaryTree(7);


    cout<<"Preorder Traversal : ";
    Preorder(root);
    cout<<"\n";
    cout<<"InOrder Traversal : ";
    Inorder(root);
    cout<<"\n";
    cout<<"PostOrder Traversal : ";
    Postorder(root);
    cout<<"\n";
    return 0;
}