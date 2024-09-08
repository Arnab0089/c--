#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

Node* addtwoNumbers(Node* l1,Node* l2){
    Node* dummy=new Node(0);
    Node* temp1=dummy;
    int carry=0;    
    while(l1!=NULL || l2!=NULL || carry){
        int sum=carry;
        if(l1!=NULL){
            sum+=l1->data;
            l1=l1->next;
        }
        if(l2!=NULL){
            sum+=l2->data;
            l2=l2->next;
        }
        carry=sum/10;
        temp1->next=new Node(sum%10);
        temp1=temp1->next;
        
    }
    return dummy->next;
}

void printList(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* head1=new Node(2);
    head1->next=new Node(4);
    head1->next->next=new Node(3);
    Node* head2=new Node(5);
    head2->next=new Node(6);
    head2->next->next=new Node(4);
    printList(head1);
    printList(head2);
    Node* newhead=addtwoNumbers(head1,head2);
    printList(newhead);
    return 0;
}