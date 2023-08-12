// preorder and inorder

#include<iostream>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
    node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};


int search(int inorder[],int st ,int en,int key){
    for (size_t i = st; i <=en; i++)
    {
        if(inorder[i]==key){
            return i;
        }
    }
    return -1;
}

node* buildtree(int preorder[],int inorder[],int st,int en){
    static int idx=0;
    if (st>en)
    {
        return NULL;
    }
    int curr=preorder[idx++];
    node* nod=new node(curr);
    if (st==en)
    {
        return nod;
    }
    int pos= search(inorder,st,en,curr);
    nod->left=buildtree(preorder,inorder,st,pos-1);
    nod->right=buildtree(preorder,inorder,pos+1,en);
    return nod;
    
}

node* buildtree2(int postorder[],int inorder[],int st,int en){
    static int idx=6;
    if (st>en)
    {
        return NULL;
    }
    int curr=postorder[idx--];
    node* nod=new node(curr);
    if (st==en)
    {
        return nod;
    }
    int pos= search(inorder,st,en,curr);
    nod->right=buildtree2(postorder,inorder,pos+1,en);
    nod->left=buildtree2(postorder,inorder,st,pos-1);
    
    return nod;
    
}

void prerder(node* root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    prerder(root->left);
    prerder(root->right);

}

int main(){
    int preorder[]={1 ,2, 4, 5, 3, 6, 7 };
    int inorder[]={4, 2, 5, 1, 6, 3, 7};
    int postorder[]={4, 5, 2, 6, 7, 3, 1};
    node* root=buildtree(preorder,inorder,0,6);
    prerder(root);
    cout<<endl;
    node* root2=buildtree2(postorder,inorder,0,6);
    prerder(root2);
    
}