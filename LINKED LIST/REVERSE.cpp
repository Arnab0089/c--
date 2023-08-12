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


// Reverse A Linked List
node* reverse(node* &head){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    while (currptr!=NULL)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        
        prevptr=currptr;
        currptr=nextptr;
    }
    return prevptr;
}

// Recursive way
node* recursivereverse(node* &head){
    if(head==NULL||head->next==NULL){
        return head;
    }
    node* newhead=recursivereverse(head->next);
    head->next->next=head;
    head->next=NULL;
    return newhead;
}


int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    // insertAtHead(head,6);
    // search(head,5);
    // deletion(head,2);
    // deleteAThead(head);
    display(head);
    node* newhead=recursivereverse(head);
    display(newhead);
    return 0;
}