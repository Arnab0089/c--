#include<iostream>
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

 int Search(int inorder[],int start,int end,int curr){
    for(int i=start;i<=end;i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
 }

Node* BuildeTree(int inorder[],int preorder[], int start,int end){
    static int idx=0;
    if(start>end){
        return NULL;
    }
    int cuurent=preorder[idx];
    idx++;
    Node* node=new Node(cuurent);
    if(start==end){
        return node;
    }
    int pos=Search(inorder,start,end,cuurent);
    node->left=BuildeTree(inorder,preorder,start,pos-1);
    node->right=BuildeTree(inorder,preorder,pos+1,end);
    return node;
}
void inorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    inorderPrint(root->left);
    cout<<root->data<<" ";
    inorderPrint(root->right);
}

int main(){
    int inorder[]={4,2,1,5,3};
    int preorder[]={1,2,4,3,5};
    Node* root=BuildeTree(inorder,preorder,0,4);
    inorderPrint(root);
    return 0;
}