#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;

    node(int val){
       data=val;
        next=NULL;
    }   
};
void insertAtHead(node* &head,int val){
   node* n= new node(val);
    if (head==NULL)
    {
        head=n;
        return;
    }
    n->next=head;
    head=n;

}


void insertAtTail(node* &head,int val){
    if (head==NULL)
    {
        insertAtHead(head,val);
        return;
    }

    node* n=new node(val);
    node* temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=n;
    
}

int multiplication(node* &head1,node* &head2){
    node* temp1=head1;
    node* temp2=head2;
    int count1=0,count2=0;

    while (temp1!=NULL)
    {
        count1=(count1*10+temp1->data);
        temp1=temp1->next;
    }

    while (temp2!=NULL)
    {
        count2=(count2*10+temp2->data);
        temp2=temp2->next;
    }
    
    return (count1*count2);
    
}

void display(node* head){
    node* temp=head;
    while (temp!=NULL)
    {
        
        cout<<temp->data;
        if (temp->next!=NULL)
        {
            cout<<"->";
        }
        
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node* head1=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);

    node* head2=NULL;
    insertAtTail(head2,4);
    insertAtTail(head2,5);
    display(head1);
    display(head2);

    cout<<"MULtiplication Number is"<<multiplication(head1,head2);
}