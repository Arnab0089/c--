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

node* merge(node* &head1,node* &head2){
    node* p1=head1;
    node* p2=head2;
    node* dummynode= new node(-1);
    node* p3=dummynode;
    while (p1!=NULL&&p2!=NULL)
    {
        if (p1->data<p2->data)
        {
            p3->next=p1;
            p3=p3->next;
            p1=p1->next;
        }
        else
        {
            p3->next=p2;
            p3=p3->next;
            p2=p2->next;
        }
        
        
    }
    while (p1!=NULL)
    {
        p3->next=p1;
        p3=p3->next;
        p1=p1->next;
    }
    
    while (p2!=NULL)
    {
        p3->next=p2;
        p3=p3->next;
        p2=p2->next;
    }

    return dummynode->next;
}

int main(){
    node* head=NULL;
    node* head1=NULL;
    insertAtTail(head,1);
    insertAtTail(head,3);
    insertAtTail(head,5);
    insertAtTail(head1,2);
    insertAtTail(head1,4);
    insertAtTail(head1,6);
    node* newhead=merge(head,head1);
    display(newhead);


    return 0;
}