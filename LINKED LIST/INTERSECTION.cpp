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

int intersection(node* &head1,node* &head2){
    int l1=length(head1);
    int l2=length(head2);
    int d=0;
    node* ptr1;
    node* ptr2;
    if (l1>l2)
    {
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else 
    {
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    while (d)
    {
        ptr1=ptr1->next;
        if (ptr1==NULL)
        {
            return -1;

        }
        
        d--;
    }
    while (ptr1!=NULL&& ptr2!=NULL)
    {
        if (ptr1==ptr2)
        {
            return ptr1->data;
        }
        
        ptr1=ptr1->next;
        ptr2=ptr2->next;

    }
    return -1;
}


void intersect(node* &head1,node* &head2,int pos ){
    node* temp1=head1;
    pos--;
    while (pos--)
    {
        temp1=temp1->next;
    }
    node* temp2=head2;
    while (temp2->next!=NULL){
        temp2=temp2->next;
    }
    temp2->next=temp1;
    
    
}

int main(){
    node* head1=NULL;
    node* head2=NULL;
    insertAtTail(head1,1);
    insertAtTail(head1,2);
    insertAtTail(head1,3);
    insertAtTail(head1,4);
    insertAtTail(head1,5);
    insertAtTail(head1,6);
    insertAtTail(head2,10);
    insertAtTail(head2,9) ;  
   intersect(head1,head2,3);
   display(head1);
   display(head2);
   cout<<intersection(head1,head2);

    return 0;
}