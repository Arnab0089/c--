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
void inorder(Node* root){
    if (root==NULL)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

vector<int> leftView(Node* root){
    vector<int> ans;
    if (root==NULL)
    {
        return ans;
    }
    queue<Node* > q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        for (size_t i = 0; i < n; i++)
        {
            Node* temp=q.front();
            q.pop();
            if (i==0)
            {
                ans.push_back(temp->data);
            }
            if (temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
            
        }
        
    }
    return ans;
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
   vector<int> left=leftView(root);
   int n=left.size();
   for (size_t i = 0; i < n; i++)
   {
        cout<<left[i]<<" ";
   }
   
}