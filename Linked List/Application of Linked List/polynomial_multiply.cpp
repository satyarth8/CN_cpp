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
            if(temp!= nullptr){
            if(temp->coeff>0)
                cout<<" + ";
            else
                cout<<" ";
            }
        }
    }
}
void poly_multiply(node* head1,node* head2)
{
    node* ptr1=head1;
    node*ptr2 =head2;
    node* head3=nullptr;
    while(ptr1!=nullptr)
    {

        while(ptr2!=nullptr)
        {
            head3=insert(head3,ptr1->coeff * ptr2->coeff,ptr1->exp + ptr2->exp);
            ptr2=ptr2->next;
        }
        ptr1=ptr1->next;
        ptr2=head2;
    }

    print(head3);
    
    cout<<"\nAfter simplification : ";

    node* ptr3= head3;
    node* temp=nullptr;
    while(ptr3->next!=nullptr)
    {
        if(ptr3->exp == ptr3->next->exp)
        {
            ptr3->coeff=ptr3->coeff + ptr3->next->coeff;
            temp=ptr3->next;
            ptr3->next=ptr3->next->next;
            free(temp);
        }
        else
        {
            ptr3=ptr3->next;
        }
    }
    print(head3);
}
int main() {
    node* head1= nullptr;
    node* head2=nullptr;
    cout<<" Enter the polynomial 1"<<endl;
    head1=create(head1);
    cout<<" Enter the polynomial 2"<<endl;
    head2=create(head2);
    poly_multiply(head1,head2);
    return 0;
}