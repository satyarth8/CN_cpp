#include <iostream>
using namespace std;

struct node{
    int data;
    struct node* prev;
    struct node* next;
};
// add to empty
node* addtoempty(node* head , int value)
{
    head->prev=nullptr;
    head->next=nullptr;
    head->data=value;
    return head;
}
// add to end
node* addtoend(node* head,int value)
{
     node* ptr=head;
     node* temp=new node;
     temp->data=value;
     temp->next=nullptr;
     while(ptr->next!=nullptr)
     {
         ptr=ptr->next;
     }
     ptr->next=temp;
     temp->prev=ptr;
     return head;
    // node* temp=new node;
    // temp->data=value;
    // node* ctr=head;
    // while(ctr->next!=nullptr){
    //     ctr=ctr->next;
    // }
    // ctr->next=temp;
    // temp->prev=ctr;
    // temp->next=nullptr;
    // return head;


}
// create list

//print
void print(node* head)
{
    node* ptr=head;
    int count =0;
    while(ptr!=nullptr)
    {
        count++;
        cout<<"NODE # "<<count<<endl;
        cout<<"my location:"<<ptr<<endl;
        cout<<"prev :"<<ptr->prev<<endl;
        cout<<"next :"<<ptr->next<<endl;
        cout<<"value="<<ptr->data<<endl<<endl<<endl;
        ptr=ptr->next;
    }
}

node* reverse(node* head)
{
    node* ptr1=head;
    node* ptr2=ptr1->next;
    ptr1->next=nullptr;
    ptr1->prev=ptr2;
    while(ptr2!=nullptr)
    {
        ptr2->prev=ptr2->next;
        ptr2->next=ptr1;
        ptr1=ptr2;
        ptr2=ptr2->prev;
    }
    return ptr1;
}
int main() {
    node* head=new node;
    int num;
    cout<<" Enter the number of elements you want:"<<endl;
    cin>>num;
    if(num==0)
        cout<<"Empty hai";
    else
    {
        int n1;
        cout<<"Enter the value for the node 1 :"<<endl;
        cin>>n1;
        head= addtoempty(head, n1);
        for(int i=1;i<num;i++)
        {
            cout<<"Enter the value for the node "<<i+1<<endl;
            cin>>n1;
            head=addtoend(head,n1);
        }
    }

    print(head);
    cout<<endl<<"After reverse: "<<endl;
    head=reverse(head);
    print(head);
    return 0;
}