#include <iostream>

using namespace std;
struct node{
    double coeff;
    int exp;
    node* next;
};
//Insert like a sorted singly linked list
node* insert(node* head, double co , int ex)
{
    node* temp;
    node* newp=new node;
    newp->coeff=co;
    newp->exp=ex;
    newp->next=nullptr;
    if(head==nullptr || ex> head->exp)
    {
        newp->next=head;
        head=newp;
    }
    else{
        temp=head;
        while(temp->next!=nullptr && temp->next->exp>ex)
        {
            temp=temp->next;
        }
        newp->next=temp->next;
        temp->next=newp;
    }
    return head;
}
node* create( node* head )
{
    int n;
    cout<<"enter the no. of terms :";
    cin>>n;
    double coeff;
    int expo;
    for( int i=1;i<=n;i++)
    {
        cout<<"Enter the coeff for term "<<i<<" : ";
        cin>>coeff;
        cout<<"Enter the expo for term "<<i<<" : ";
        cin>>expo;
        head= insert( head, coeff, expo);
    }
    return head;
}
void print(node* head)
{
    if(head==nullptr)
    {
       cout<<" no polynomial";
    }
    else{
        
        node* temp=head;
        while(temp!=nullptr)
        {
            cout<<temp->coeff<<"x^"<<temp->exp;
            temp=temp->next;
            if(temp->coeff>0)
                cout<<"+";
            else
                cout<<"";
        
        }
    }
}
int main() {
    node* head= nullptr;
    cout<<" Enter the polynomial"<<endl;
    head=create(head);
    print(head);

    return 0;
}