#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
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


vector<int> reverselevel(Node* root){
    vector<int> ans;
    if (root==NULL)
    {
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp=q.front();
        ans.push_back(temp->data);
        q.pop();
        if (temp->right)
        {
            q.push(temp->right);
        }
        
        if (temp->left)
        {
            q.push(temp->left);
        }

    }
    reverse(ans.begin(),ans.end());
}

int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);


    vector<int> reverse1=reverselevel(root);
    int n=reverse1.size();
    for (size_t i = 0; i < n; i++)
    {
        cout<<reverse1[i]<<" ";
    }
    cout<<endl;
    return 0;
    


    
}