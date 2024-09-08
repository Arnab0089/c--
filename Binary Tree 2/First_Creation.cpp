#include<iostream>
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

void preorder(struct Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(struct Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(struct Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void LevelorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node* >q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* node =q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    } 
}

// int sumNodeAtK(Node* root,int k){
//     // if(root==NULL){
//     //     return -1;
//     // }
//     // queue<Node* >q;
//     // q.push(root);
//     // q.push(NULL);
//     // int level=0,sum=0;
//     // while (!q.empty()){}
//     // {
//     //     Node* node=q.front();
//     //     q.pop();
//     //     if(node!=NULL){
//     //         if(level==k){
//     //             sum+=node->data;
//     //         }
//     //         if(node->left){
//     //             q.push(node->left);
//     //         }
//     //         if(node->right){
//     //             q.push(node->right);
//     //         }
//     //     }
//     //     else if(!q.empty()){
//     //         q.push(NULL);
//     //         level++;
//     //     }
//     // }
//     // return sum;
//     if(root==NULL){
//         return -1;
//     }
//     if(k==0){
//         return root->data;
//     }
//     int left=sumNodeAtK(root->left,k-1);
//     int right=sumNodeAtK(root->right,k-1);
//     return left+right;
// }

int countALLNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return countALLNodes(root->left)+countALLNodes(root->right)+1;
}

int sumALLNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    return sumALLNodes(root->left)+sumALLNodes(root->right)+root->data;
}

int sumNodeAtK(Node* root,int k){
    if(root==NULL){
        return -1;
    }
    queue<Node* >q;
    q.push(root);
    q.push(NULL);
    int level=0,sum=0;
    while (!q.empty())
    {
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }
    }
    return sum;
}
int main(){
    struct Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);   
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<"Preorder Traversal: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder Traversal: ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder Traversal: ";
    postorder(root);
    cout<<endl;
    cout<<"Levelorder Traversal: ";
    LevelorderTraversal(root);
    cout<<endl;
    cout<<"Sum of Nodes at Kth level: "<<sumNodeAtK(root,1);
    cout<<endl;
    cout<<"Sum of All Nodes: "<<sumALLNodes(root);
    cout<<endl;
    cout<<"Count of All Nodes: "<<countALLNodes(root);
    
    
    return 0;
}