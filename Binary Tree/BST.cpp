#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node( int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
Node* insrtBST(Node* root,int val){
    if (root==NULL)
    {
        return new Node(val);
    }
    if (val<root->data)
    {
        root->left=insrtBST(root->left,val);
    }

    if (val>root->data)
    {
        root->right=insrtBST(root->right,val);
    }
    return root;
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

Node* lca(Node* root,int n1,int n2){
    if (root==NULL)
    {
        return NULL;
    }
    if (root->data==n1||root->data==n2)
    {
        return root;
    }
    Node* left=lca(root->left,n1,n2);
    Node* right=lca(root->right,n1,n2);
    if (left==NULL&&right==NULL)
    {
        return NULL;
    }
    if (left!=NULL&&right!=NULL)
    {
        return root;
    }
    if (left!=NULL)
    {
        return lca(root->left,n1,n2);
    }
    if (right!=NULL)
    {
        return lca(root->right,n1,n2);
    }
    
}

int Dis(Node* root,int n1,int dist){
    if (root==NULL)
    {
        return -1;
    }
    if (root->data==n1)
    {
        return dist;
    }
    int left=Dis(root->left,n1,dist+1);
    if (left!=-1)
    {
        return left;
    }
    return Dis(root->right,n1,dist+1);
    
}


int findDis(Node* root,int n1,int n2){
    Node* LCA=lca(root,n1,n2);
    int d1=Dis(LCA,n1,0);
    int d2=Dis(LCA,n2,0);
    return d1+d2;
}
// Delete in BST
Node* inoderSucc(Node* root){
    Node* curr=root;
    while (curr&&curr->left!=NULL)
    {
        curr=curr->left;
    }
    return curr;
}


Node* deleteBST(Node* root,int key){
    if (root==NULL)
    {
        return root;
    }
    
    if(key<root->data){
        root->left =deleteBST(root->left,key);
    }
    else if (key>root->data)
    {
        root->right= deleteBST(root->right,key);
    }
    else{
        if (root->left==NULL)
        {
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        
        Node* temp=inoderSucc(root->right);
        root->data=temp->data;
        root->right=deleteBST(root->right,temp->data);
    }
    return root;
}


// Node* findMin(Node* node) {
//     while (node->left != NULL) {
//         node = node->left;
//     }
//     return node;
// }

// Node* deleteBST(Node* root, int key) {
//     if (root == NULL) {
//         return root;
//     }

//     if (key < root->data) {
//         root->left = deleteBST(root->left, key);
//     } else if (key > root->data) {
//         root->right = deleteBST(root->right, key);
//     } else {
//         if (root->left == NULL) {
//             Node* temp = root->right;
//             free(root);
//             return temp;
//         } else if (root->right == NULL) {
//             Node* temp = root->left;
//             free(root);
//             return temp;
//         }

//         Node* temp = findMin(root->right);
//         root->data = temp->data;
//         root->right = deleteBST(root->right, temp->data);
//     }
//     return root;
// }
int main(){
   Node* root=new Node(5);
   root->left=new Node(1);
   root->right=new Node(7);
   root->left->right=new Node(3);
   root->left->right->left=new Node(2);
   root->left->right->right=new Node(4);
   inorder(root);

   cout<<endl;

   Node* temp=lca(root,4,2);
   cout<<temp->data<<" ";
   cout<<endl;
//   root= deleteBST(root,1);

cout<<findDis(root,4,7);
   
   
//     inorder(root);
}