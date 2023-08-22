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

  bool checkLevel(Node* root,int level,int* leftlevel){
        if(root==NULL){
            return true;
        }
        if(root->left==NULL&& root->right==NULL){
            if(*leftlevel==0){
               *leftlevel=level;
                return true;
            }
            return (level==*leftlevel);
        }
        return (checkLevel(root->left,level+1,leftlevel)&&checkLevel(root->right,level+1,leftlevel));
    }
    
    bool check(Node *root)
    {
      int level=0,leftlevel=0;
      return checkLevel(root,level,&leftlevel);
    }
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);

    cout<<check(root)<<endl;
   
}