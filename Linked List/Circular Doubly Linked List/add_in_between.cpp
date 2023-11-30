#include <iostream>

using namespace std;

struct node 
{
    node* prev=nullptr;
    node* next=nullptr;
    int data;
};
node* create_dll(int val)
{
    node* temp= new node;
    temp->data=val;
    temp->prev=temp;
    temp->next=temp;
    return temp;
}
void print(node* tail)
{
    node* temp=tail->next;

    do
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp!=tail->next);

}
node* add_at_end(   node* tail,int val )
{
    node* temp=new node;
    temp->data=val;
    //prev connection;
    temp->next=tail->next;
    temp->prev=tail;
    tail->next=temp;
    return temp;

}
/*node* add_at_pos(node* tail, int pos, int val=0) {
    node* ptr=tail->next;
    node* temp=new node;
    temp->data=val;
    while(pos>1)
    {
        ptr=ptr->next;
        pos--;
    }
    node* prnde=ptr;
    node* nxnde=ptr->next;
    temp->prev=prnde;
    temp->next=nxnde;
    prnde->next=temp;
    nxnde->prev=temp;
    if(prnde==tail)
    {
        return temp;
    }
    return tail;
}*/
node* add_at_pos(node* tail, int data,int pos)
{
    node* newp=new node;
    newp->data=data;
    node* temp=tail->next;
    while(pos>1)
    {
        temp=temp->next;
        pos--;
    }
    newp->prev=temp;
    newp->next=temp->next;
    temp->next->prev=newp;
    temp->next=newp;
    if(temp==tail)
        tail=tail->next;
    return tail;
}
int main() 
{
    node* tail=nullptr;
    tail=create_dll(45);
    tail=add_at_end(tail,334);
    tail=add_at_end(tail,223);
  
    cout<<endl;
    tail=add_at_pos(tail,999,3);
    print(tail);
    return 0;
}