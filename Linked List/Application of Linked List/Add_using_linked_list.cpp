#include <iostream>

using namespace std;
struct node{
    int data;
    node* link;
};
void deleteList(node* head) {
    while (head != nullptr) {
        node* temp = head;
        head = head->link;
        delete temp;
    }
}
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
            cout<<ptr->data;
            ptr=ptr->link;
            cout<<" -> ";
    
        }
        cout<<ptr->data;
    }
}
node* push(node* head, int val)
{
    node* newp=new node;
    newp->data=val;
    newp->link=head;
    head=newp;
    return head;
}
node*  add(node* head1, node* head2)
{
    if(head1->data==0)
    {
        return head2;
    }
    if(head2->data==0)
    {
        return head1;
    }
     node * ptr1=head1;
     node* ptr2=head2;
    node* head3=nullptr;
    int carry=0,sum;

    while(ptr1||ptr2)
    {
        sum=0;
        if(ptr1)
            sum+= ptr1->data;
        if(ptr2)
        {
            sum+=ptr2->data;
        }
        sum+=carry;

        carry=sum/10;
        sum=sum%10;
        
        head3=push(head3,sum);

        if(ptr1)
            ptr1=ptr1->link;
        if(ptr2)
        {
            ptr2=ptr2->link;
        }
    }
        if(carry)
        {
            head3=push(head3,carry);
        }

    return head3;

}
void back2num(struct node* head)
{
    node* temp=head;
    while(temp)
    {
        cout<<temp->data;
        temp=temp->link;
    }
    return;
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
    head1=reverse_LL(head1);
    print(head1);
    cout<<" "<<endl;
    head2=reverse_LL(head2);
    print(head2);
    cout<<" "<<endl;
    node* head3=nullptr;
    head3= add(head1,head2);
    cout<<"Resultant Linked List "<<endl;
    back2num(head3);


    deleteList(head1);
    deleteList(head2);
    deleteList(head3);
    return 0;
}