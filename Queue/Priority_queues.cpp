#include <iostream>

using namespace std;

struct node{
    int data;
    int priority;
    node* link;
};
node* front=nullptr;

int isEmpty()
{
    return(front==nullptr);
}
void enqueue(int data, int priority)
{
    node* temp=new node;
    temp->data=data;
    temp->priority=priority;
    temp->link=nullptr;
    if(isEmpty()||priority<front->priority)
    {
        //add at begin 
        temp->link=front;
        front=temp;   
    }
    else
    {
        // add in between 
        node* ptr=front;
        while(ptr->link!=nullptr && ptr->link->priority<=priority)
        {
            ptr=ptr->link;
        }
        temp->link=ptr->link;
        ptr->link=temp;
    }
}

int deque()
{
    node* temp=front;
    if(isEmpty())
    {
        cout<<"The queue is empty";
        exit(1);
    }
    int data=front->data;
    cout<<"Deleted ELement"<<front->data<<" with priority :"<<front->priority<<endl;
    front=front->link;
    temp=nullptr;
    return data;
}

void print()
{
    node* ptr=front;
    if(isEmpty())
    {
        cout<<"The queue is empty";
        exit(1);
    }
    while(ptr!=nullptr)
    {
        cout<<ptr->data<<":"<<ptr->priority<<" , ";
        ptr=ptr->link;
    }
    cout<<endl;
}
int main() {
    int choice, data,prt;
    while(1)
    {
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Print"<<endl;
        cout<<"4. Quit"<<endl;
        cout<<"----------------"<<endl;
        cout<<"Enter your choice "<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<"Enter the value : "<<endl;
                cin>>data;
                cout<<"Enter the priority : "<<endl;
                cin>>prt;
                enqueue(data,prt);
                break;
            case 2:
                deque();
                break;
            case 3:
                print();
                break;
            case 4:
                exit(1);
            deault:
                cout<<"-------------";
                cout<<"Valid Input do";
                cout<<"-------------";
        }
    }
    return 0;
}