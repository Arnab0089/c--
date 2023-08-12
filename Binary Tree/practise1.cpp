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

int search(int inorder1[],int st,int en,int curr){
    for (size_t i = st; i < en; i++)
    {
        if(inorder1[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* BuildTree(int preorder1[],int inorder1[],int st,int en){
    static int idx=0;
    if(st>en){
        return NULL;
    }
    int curr=preorder1[idx++];
    Node* root=new Node(curr);
    if (st==en)
    {
        return root;

    }
    int pos=search( inorder1, st, en, curr);
    root->left=BuildTree(preorder1,inorder1,st,pos-1);
    root->right=BuildTree(preorder1,inorder1,pos+1,en);
    return root; 

}
Node* BuildTree2(int postorder1[],int inorder1[],int st,int en){
    static int idx1=5;
    if(st>en){
        return NULL;
    }
    int curr=postorder1[idx1--];
    Node* root=new Node(curr);
    if (st==en)
    {
        return root;

    }
    int pos=search( inorder1, st, en, curr);
    root->right=BuildTree2(postorder1,inorder1,pos+1,en);
    root->left=BuildTree2(postorder1,inorder1,st,pos-1);
    
    return root; 

}
void levelorderTraversal(Node* root){
    if (root==NULL)
    {
        return;

    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
    
    
}
int SumAtK(Node* root,int k){
        if (root==NULL)
    {
        return -1;

    }
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    int sum=0,lvl=0;
    while (!q.empty())
    {
        Node* temp=q.front();
        q.pop();
        if(temp!=NULL){
            if (lvl==k)
            {
                sum+=temp->data;
            }
            
        
            if (temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
        }
        else if(!q.empty()){
            q.push(NULL);
             lvl++;
        }
       
    }
    return sum;
    
}

int height(Node* root){
    if (root==NULL)
    {
        return 0;
    }
    
    int lheight=height(root->left);
    int rheight=height(root->right);

    return max(lheight,rheight)+1;
}


int diameter(Node* root){
    if (root==NULL)
    {
        return 0;
    }
    int lheight=height(root->left);
    int rheight=height(root->right);
    int currdia=lheight+rheight+1;
    int leftDia=diameter(root->left);
    int rightDia=diameter(root->right);

    return max(currdia,max(leftDia,rightDia));
}

void sumReplacement(Node* root){
    if (root==NULL)
    {
        return ;
    }
    
    sumReplacement(root->left);
    sumReplacement(root->right);
    if (root->left!=NULL)
    {
        root->data+=root->left->data;
    }
    if (root->right)
    {
        root->data+=root->right->data;

    }
    
}
bool BalancedHeight(Node* root){
    if (root==NULL)
    {
        return true;
    }
    
    if (BalancedHeight(root->left)==false)
    {
        return false;
    }
    if (BalancedHeight(root->right)==false)
    {
        return false;
    }
    int lh=height(root->left);
    int rh=height(root->right);
    if (abs(lh-rh)<=1)
    {
        return true;
    }
    else{
        return false;
    }
    
    
}

void rightView(Node* root){
    if(root==NULL){
        return ;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n=q.size();
        for (size_t i = 0; i <n; i++)
        {
            Node* temp=q.front();
            q.pop();
            if (i==n-1)
            {
                cout<<temp->data<<" ";
            }
            if (temp->left!=NULL)
            {
                q.push(temp->left);
            }
            
            if (temp->right!=NULL)
            {
                q.push(temp->right);
            }
            
        }
        
    }
    
}

Node* LCA(Node* root ,int n1,int n2){
    if (root==NULL)
    {
        return NULL;

    }
    if (root->data==n1||root->data==n2)
    {
        return root;
    }
    Node* left=LCA(root->left,n1,n2);
    Node* right=LCA(root->right,n1,n2);
    if (left==NULL&&right==NULL)
    {
        return NULL;

    }
    if (right!=NULL||left!=NULL)
    {
        return root;
    }
    if (left!=NULL)
    {
        return LCA(root->left,n1,n2);
    }
    return LCA(root->right,n1,n2);
    

}

int FindDis(Node* root,int k,int dist){
    if (root==NULL)
    {
        return -1;
    }
    if (root->data==k)
    {
        return dist;
    }
    int left=FindDis(root->left,k,dist+1);
    if (left!=-1)
    {
        return left;
    }
    return FindDis(root->right,k,dist+1);
    
}

int Dis(Node* root,int n1,int n2){
    Node* lca=LCA(root,n1,n2);
    int d1=FindDis(lca ,n1,0);
    int d2=FindDis(lca,n2,0);
    return d1+d2;
}




void leftView(Node* root){
    if(root==NULL){
        return ;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        int n=q.size();
        for (size_t i = 0; i <n; i++)
        {
            Node* temp=q.front();
            q.pop();
            if (i==0)
            {
                cout<<temp->data<<" ";
            }
            if (temp->left!=NULL)
            {
                q.push(temp->left);
            }
            
            if (temp->right!=NULL)
            {
                q.push(temp->right);
            }
            
        }
        
    }
    
}
void flatten(Node* root){
    if (root==NULL||root->left==NULL&&root->right==NULL)
    {
        return;
    }
    if (root->left!=NULL)
    {
        flatten(root->left);
        Node* temp=root->right;
        root->right=root->left;
        root->left=NULL;
        Node* t=root->right;
        while (t->right!=NULL)
        {
         t=t->right;

        }
        t->right=temp;
        
    }
    
    flatten(root->right);
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->right=new Node(6);


    cout<<"Level order Traversal : ";
    levelorderTraversal(root);
    cout<<endl;
    cout<<"Sum at Kth level : ";
    cout<<SumAtK(root,2);
    cout<<endl;
    cout<<"Height of the binary tree : "<<height(root)<<endl;
    cout<<"Diameter of the binary tree : "<<diameter(root)<<endl;
   if (BalancedHeight(root)==true)
   {
    cout<<"The tree is Balanced height"<<endl;
   }
   else{
      cout<<"The tree is Not Balanced height"<<endl;
   }
   rightView(root);
   cout<<endl;
   leftView(root);
   cout<<endl;
   cout<<Dis(root,4,6)<<endl;

   flatten(root);
   inorder(root);
    // cout<<"Sum replacement of Binary tree : ";
    // sumReplacement(root);
    // levelorderTraversal(root);
    // cout<<endl;



    //     1
    //    / \
    //   2   3
    //  /\    \
    // 4  5    6

// printing preorder
//     preoder(root);
//     cout<<endl;

// print inorder
//     inorder(root);
//     cout<<endl;
// printing postorder
//     postorder(root);


    // int preorder[]={1,2,4,5,3,6};
    // int inorder[]={4,2,5,1,3,6};
    // int postorder[]={4,5,2,6,3,1};
    // Node* root=BuildTree(preorder,inorder,0,5);
    // preoder(root);
    // cout<<endl;
    //  Node* root2=BuildTree2(postorder,inorder,0,5);
    //  postordr(root2);

}