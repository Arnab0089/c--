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

// REverse k pair nodes in a linked list
node* reversek(node* &head,int k){
    node* prevptr=NULL;
    node* currptr=head;
    node* nextptr;
    int count=0;
    while (currptr!=NULL&&count<k)
    {
        nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr=currptr;
        currptr=nextptr;
        count++;
    }
    if (nextptr!=NULL)
    {
        head->next=reversek(nextptr,k);
    }
    return prevptr;
    
}

int main(){
    node* head=NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    // insertAtHead(head,6);
    //  search(head,5);
    // deletion(head,2);
    // deleteAThead(head);



    display(head);
    return 0;
}