#include<iostream>
using namespace std;

// creating linked list
class node{
    public:
    int data;
    node* next;

    node(int val){
        data=val;
        next=NULL;
    }
};

// inserting at the end
void insertAtTail(node* &head,int val){
    
    

    node* n=new node(val);
    if (head==NULL)
    {
        head=n;
        return;
    }
    
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    
}

// insert at head
void insertAtHead(node* &head,int val){
    node* n= new node(val);
    n->next=head;
    head=n;
}


// displaying the linked list
void display(node* head){
    node* temp =head;
      while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    
}
// searching  a node
bool search(node* head,int key){
    node* temp=head;
    while (temp!=NULL)
    {
        if (temp->data==key)
        {
            cout<<"key is found"<<endl;
            return true;
        }
        temp=temp->next;
    }
    return false;
}


// deletion of linked list
void deletion(node* &head,int val){
    node* temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    node *todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void deleteAThead(node* &head){
    node* todelete=head;
    head=head->next;
    delete todelete;
}

int length(node* head){
    node* temp=head;
    int cont=0;
    while (temp!=NULL)
    {
        temp=temp->next;
        cont++;
    }
    return cont;
    
}

node* kAppend(node* &head,int k){
    node* newhead;
    node* newtail;
    node* tail=head;
    int l=length(head);
    int count=1;
    while (tail->next!=NULL)
    {
        if (count==l-k)
        {
            newtail=tail;
        }
        if (count==l-k+1)
        {
            newhead=tail;
        }
        count++;
        tail=tail->next;
        
    }
    newtail->next=NULL;
    tail->next=head;
    return newhead;
    

}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtHead(head,6);
     display(head);
    node* newnode=kAppend(head,3);
   
    display(newnode);
    return 0;
}