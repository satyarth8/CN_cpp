#include <iostream>

using namespace std;
struct node{
    int data;
    node* link;
};
void print(node* head){
    node* ptr=head;
    if(ptr==nullptr)
    {
        cout<<"Empty ";
    }
    else
    {
        while(ptr->link!=nullptr)
        {
            cout<<" : "<<ptr->data;
            ptr=ptr->link;
    
        }
        cout<<ptr->data;
    }
}
node* add_node_start( node* head, int digit)
{
    node* temp=new node;
    temp->link=nullptr;
    temp->data=digit;
    temp->link=head;
    return temp;
}
node* createLL(node* head, int val)
{
    int n=val;
    while(n!=0)
    {
        head=add_node_start(head,int(n%10));
        n=n/10;
    }
    print(head);
    return head;
}
node* reverse_LL(node* head)
{
    if(head==NULL)
    {
        return head;
    }
    node* current =nullptr;
    node* next=head->link;
    head->link=nullptr;

    while(next!=nullptr)
    {
        current =next;
        next=next->link;
        current->link=head;
        head=current;
    }
    return head;
}

int main() {
    int a,b;
    cout<<"enter the 2 no. ";
    cin>>a>>b;
    node*head1=new node;
    cout<<"\nLinked List representation of first element ";
     head1=nullptr;
    head1=createLL(head1,a);
    node*head2=new node;
    cout<<"\nLinked List representation of second element ";
    head2=nullptr;
    head2=createLL(head2,b);

    cout<<"\nLinked List after reversing :";
    print(reverse_LL(head1));
    cout<<" "<<endl;
    print(reverse_LL(head2));
    return 0;
}