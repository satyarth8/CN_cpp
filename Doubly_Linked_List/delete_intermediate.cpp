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
//delete at position
node* del_at_pos(node* head, int position)
{
    node* temp= head;
    node* temp2=nullptr;
    if(position==1)
    {
        head=head->next;
        head->prev=nullptr;
        free(temp);
        return head;
    }
    while(position!=1)
    {
        temp=temp->next;
        position--;
    }
    temp2=temp->prev;
    temp2->next=temp->next;
    temp->next->prev=temp2;
    free(temp);
    return head;
}
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
    int pos;
    cout<<"enter the postion of value you want to be deleted";
    cin>>pos;
    head=del_at_pos(head,pos);
    print(head);
    
    
    return 0;
}