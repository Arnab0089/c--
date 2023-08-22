#include<iostream>
#include<vector>
#include<stack>
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

vector<int> zigzagTraversal(Node* root){
    vector<int> ans;
    if (root==NULL)
    {
        return ans;
    }
    stack<Node*> currLevel;
    stack<Node* >nextLevel;
    bool lefttoRight=true;
    currLevel.push(root);
    while (!currLevel.empty())
    {
        Node* temp=currLevel.top();
        currLevel.pop();
        if (temp)
        {
            ans.push_back(temp->data);
            if (lefttoRight)
            {
                if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                
                
            }
            else 
            {
               
                if (temp->right)
                {
                    nextLevel.push(temp->right);
                }
                
                 if (temp->left)
                {
                    nextLevel.push(temp->left);
                }
            }
            
        }
        if (currLevel.empty())
        {
            lefttoRight=!lefttoRight;
            swap(currLevel,nextLevel);
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
   vector<int> zigzag=zigzagTraversal(root);
   int n=zigzag.size();
   for (size_t i = 0; i < n; i++)
   {
        cout<<zigzag[i]<<" ";
   }
   
}