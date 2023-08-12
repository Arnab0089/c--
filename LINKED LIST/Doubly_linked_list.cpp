#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node* prev;
    node(int val){
        data=val;
        next=NULL;
        prev=NULL;
    }
};

void insertAtTail(node* &head,int val){
    node* n=new node( val);
    if(head==NULL){
        head=n;
        return;
    }
    node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=n;
    n->prev=temp;
}

void insertAtHead(node* &head,int val){
    node* n=new node(val);
    n->next=head;
    head->prev=n;
    head=n;
}

void display(node* head){
    node* temp =head;
      while (temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
    
}

void deletion(node* &head,int pos){
    node* temp=head;
    while (temp->next->data!=pos)
    {
        temp=temp->next;
    }
    node* todelete=temp->next;
    temp->next=temp->next->next;
    temp->next->next->prev=temp;
    delete todelete;
}

// position wise deletion
void deletion(node* &head,int pos){
    node* temp=head;
    int count=1;
    while (temp!=NULL&&count!=pos)
    {
        temp=temp->next;
        count++;
    }
    node* todelete=temp;
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete todelete;
}
void deleteATHead(node* &head,int pos){
    node* todelte=head;
    head=head->next;
    head->prev=NULL;
    delete todelte;
}

int main(){
    node* head =NULL;
    insertAtTail(head,1);
    insertAtTail(head,2);
    insertAtTail(head,3);
    insertAtTail(head,4);
    insertAtTail(head,5);
    insertAtTail(head,6);
    insertAtHead(head,7);
    insertAtHead(head,8);
    insertAtHead(head,9);
    // deletion(head,7);
    display(head);
}