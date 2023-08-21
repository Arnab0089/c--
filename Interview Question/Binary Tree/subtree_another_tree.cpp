   bool ans=false;

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

    bool match(Node* root, Node* subRoot){
        if(root!=NULL&&subRoot!=NULL){
            bool a=match(root->left,subRoot->left);
            bool b=match(root->right,subRoot->right);
            if((root->data==subRoot->data)&&a&&b){
                return true;
            }
            else{
                return false;
            }
            
        }
        else if(root==NULL&& subRoot==NULL){
            return true;

        }
        else{
            return false;
        }
    }

    void inorder(Node* root, Node* subRoot){
        if(root){
            inorder(root->left,subRoot);
            bool x=match(root,subRoot);
            if(x){
                ans=x;
            }
            inorder(root->right,subRoot);
        }
    }


    bool isSubtree(Node* root, Node* subRoot) {
        inorder(root,subRoot);
        return ans;
    }
int main(){
    Node* root=new Node(3);
    root->left=new Node(4);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(2);

Node* subroot=new Node(4);
subroot->left=new Node(1);
subroot->right=new Node(2);

   cout<<isSubtree(root,subroot);
    


    
}
