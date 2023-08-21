#include<iostream>
#include<vector>
#include<queue>
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

void preoder(Node* root){
    if (root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preoder(root->left);
    preoder(root->right);
}
void inorder(Node* root){
    if (root==NULL)
    {
        return;

    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
    
}
void postordr(Node* root){
    if (root==NULL)
    {
        return;

    }

    postordr(root->left);
    postordr(root->right);
    cout<<root->data<<" ";
    
}
Node* BuildBST(Node* root,int val){
    if (root==NULL)
    {
        return new Node(val);
    }
    if (val<root->data)
    {
        root->left=BuildBST(root->left,val);
    }
    if (val>root->data)
    {
        root->right=BuildBST(root->right,val);
    }
    return root;
    
} 

// bool search(Node* root,int key){
//     if (root==NULL)
//     {
//         return false;
//     }
//     if (root->data==key)
//     {
//         return true;
//     }
//     if (key<root->data)
//     {
//         search(root->left,key);
//     }
//     else{
//         search(root->right,key);
//     }
// }

// Node* inorderSucc(Node* root){
//     Node* curr=root;
//     while (curr&&curr->left!=NULL)
//     {
//         curr=curr->left;
//     }
//     return curr;
// }
// Node* DeleteInBST(Node* root,int key){
//     if (key>root->data)
//     {
//         root->right=DeleteInBST(root->right,key);

//     }
//     else if(key<root->data){
//         root->left=DeleteInBST(root->left,key);
//     }
//     else{
//         if (root->left==NULL)
//         {
//             Node* temp=root->right;
//             free(root);
//             return temp;
//         }
//         else if(root->right==NULL)
//         {
//             Node* temp=root->left;
//             free(root);
//             return temp;
//         }
//         Node* temp=inorderSucc(root->right);
//         root->data=temp->data;
//         root->right=DeleteInBST(root->right,temp->data);
//     }
//     return root;
// }
// Node* constructBST(int preorder[],int *preorderIdx,int key,int min,int max,int n){
//     if (*preorderIdx>=n)
//     {
//         return NULL;
//     }
//     Node* root=NULL;
//     if (key>min&&key<max)
//     {
//         root=new Node(key);
//         *preorderIdx+=1;
//         if (*preorderIdx<n)
//         {
//             root->left=constructBST(preorder,preorderIdx,preorder[*preorderIdx],min,key,n);
//         }
//         if (*preorderIdx<n)
//         {
            
//             root->right=constructBST(preorder,preorderIdx,preorder[*preorderIdx],key,max,n);
//         }
        
        
//     }
//     return root;
    
// }
// bool checkBST(Node* root,Node* min=NULL,Node* max=NULL){
//     if (root==NULL)
//     {
//         return true;

//     }
//     if (min!=NULL&&root->data<=min->data)
//     {
//         return false;
//     }
//     if (max!=NULL&&root->data>=max->data)
//     {
//         return false;   
//     }
//     bool leftvalid=checkBST(root->left,min,root);
//     bool rightvalid=checkBST(root->right,root,max);
//     return (leftvalid&&rightvalid);
// }

// Node* sortedArrayToBST(int arr[],int start ,int end){
//     if (start>end)
//     {
//         return NULL;
//     }
//     int mid=(start+end)/2;
//     Node* root=new Node(arr[mid]);
//     root->left=sortedArrayToBST(arr,start,mid-1);
//     root->right=sortedArrayToBST(arr,mid+1,end);
//     return root;
    
// }
 
// vector<int> Diagonal(Node* root)
// {
//     vector<int> diagonalVals;
//     if (!root)
//         return diagonalVals;
 
//     // The leftQueue will be a queue which will store all
//     // left pointers while traversing the tree, and will be
//     // utilized when at any point right pointer becomes NULL
 
//     queue<Node*> leftQueue;
//     Node* node = root;
 
//     while (node) {
 
//         // Add current node to output
//         diagonalVals.push_back(node->data);
//         // If left child available, add it to queue
//         if (node->left)
//             leftQueue.push(node->left);
 
//         // if right child, transfer the node to right
//         if (node->right)
//             node = node->right;
 
//         else {
//             // If left child Queue is not empty, utilize it
//             // to traverse further
//             if (!leftQueue.empty()) {
//                 node = leftQueue.front();
//                 leftQueue.pop();
//             }
//             else {
//                 // All the right childs traversed and no
//                 // left child left
//                 node = NULL;
//             }
//         }
//     }
//     return diagonalVals;
// }
 

vector<int> Diagonal(Node* root){
    queue<Node *> q;
    vector<int> ans;
    if (root==NULL)
    {
        return ans;
    }
    q.push(root);
    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        while (temp)
        {
            
            if (temp->left)
            {
                q.push(temp->left);
            }
            ans.push_back(temp->data);
            temp=temp->right;
        }
        
    }
    return ans;
    
}
int main(){
    Node* root=NULL;
   root= BuildBST(root,5);
    BuildBST(root,1);
    BuildBST(root,3);
    BuildBST(root,4);
    BuildBST(root,2);
    BuildBST(root,7);

 vector<int> diagonalValues = Diagonal(root);
    for (int i = 0; i < diagonalValues.size(); i++) {
        cout << diagonalValues[i] << " ";
    }
    cout << endl;

//         //     5
//         //    / \
//         //   1   7
//         //    \
//         //     3
//         //    / \
//         //   2    4

//         preoder(root);
//         cout<<endl;
//         inorder(root);
//             cout<<endl;

//     if (search(root,7))
//     {
//         cout<<"Node is present 'in BST";
//     }
//     else{

//         cout<<"Node is present 'in BST";
//     }
    
//     cout<<endl;
//     Node* temp=DeleteInBST(root,1);
//     inorder(temp);

// int preorder[]={5,1,3,2,4,7};
// int preorderIdx=0;
// Node* root=constructBST(preorder,&preorderIdx,preorder[0],INT16_MIN,INT16_MAX,6);
// inorder(root);
// cout<<endl;
// preoder(root);
// cout<<endl;

// if (checkBST(root,NULL,NULL))
// {
//     cout<<"It's a Binary Seach Tree ";
// }
// else{
    
//     cout<<"It's not a Binary Seach Tree ";
// }
// cout<<endl;

// int arr[]={10,20,30,40,50,60};
// Node* root1=sortedArrayToBST(arr,0,5);
// preoder(root1);

}