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
    static int idx=end;
    if(start>end){
        return NULL;
    }
    int cuurent=preorder[idx];
    idx--;
    Node* node=new Node(cuurent);
    if(start==end){
        return node;
    }
    int pos=Search(inorder,start,end,cuurent);
    node->right=BuildeTree(inorder,preorder,pos+1,end);
    node->left=BuildeTree(inorder,preorder,start,pos-1);
    return node;
}
void preorderPrint(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderPrint(root->left);
   
    preorderPrint(root->right);
}

int main(){
    int inorder[]={4,2,1,5,3};
    // int preorder[]={1,2,4,3,5};
    int postorder[]={4,2,5,3,1};
    Node* root=BuildeTree(inorder,postorder,0,4);
    preorderPrint(root);
    return 0;
}