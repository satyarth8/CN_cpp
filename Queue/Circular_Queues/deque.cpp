#include <iostream>

using namespace std;


#define MAX 5
int deque[MAX];
int front=-1;
int rear=-1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return ((front == 0 && rear == MAX - 1) || (front == rear + 1));
}

void enqueueFront(int data)
{
    if(isFull())
    {
        cout<<"Queue Overflow";
        exit(1);
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        if(front==0)
        { // since the enuqueing in front happens by moving a block behind from the front that is front-- 
         // so when we are the start and there is no room to put the value , we will go to the end of the array 
            front=MAX-1;
        }
        else
        { // random insertion
            front=front-1;
        }
    }
    deque[front]=data;
}

void enqueueRear(int data)
{
    if(isFull())
    {
        cout<<"Queue Overflow!";
        exit(1);
    }
    if(front==-1)
    {
        front=0;
        rear=0;
    }
    else
    {
        //  we are the end of the  becuase normally what enqueue will do is to add the value after rear++
        if(rear==MAX-1)
        {
            rear=0;
            // we have already checked if the queue is full so there is room at the start to put the value
        }
        else
        { // random insertion 
            rear=rear+1;
        }
    }
    deque[rear]=data;
}

int dequeueFront()
{
    int data;
    if(isEmpty())
    {
        cout<<"Queue Underflow ";
        exit(1);
    }
    data=deque[front];
    if(front==rear)
    { // there is only one element in the queue
        
        front=-1;
        rear=-1;
    }
    else{
        // since after removing the vlaue will go front ++ , to avoiding going out of the array bound we will point the front to the start
        if(front==MAX-1)
        {
            front=0;
        }
        else
        {
            // random deletion
            front=front+1;
        }
    }
    return data;
}

int dequeueRear()
{
    int data;
    if(isEmpty())
    {
        cout<<"Queue Underflow ";
        exit(1);
    }
    data=deque[front];
    if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else{
        // since we just do rear-- to remove the last element when the rear is the beginnign then it may go out of array so we revalue the rear the end of the queue
        if(rear==0)
        {
            rear=MAX-1;
        }
        else
        {
            rear=rear-1;
        }
    }
    return data;
}
int peek()
{
    if(isEmpty())
    {
        cout<<" nahi hai kuch kal ana";
        exit(1);
    }
    return deque[front];
}

// void print()
// {
//     if(isEmpty())
//     {
//         cout<<" nahi hai kuch kal ana";
//         exit(1);
//     }
//     int i=front;
//     do
//     {
//         cout<<deque[i];
//         if(i==MAX-1)
//         {
//            i=0;
//         }
//         else
//         {
//            i++;
//         }
//     }while(i!=rear);
// }
void print()
{
    int temp;
    if(isEmpty())
    {
        cout<<"Queue Underflow";
        exit(1);
    }
    temp= front;
    if(front<=rear)
    {
        while (temp<=rear)
        {
            cout<<deque[temp]<<" ";
            temp++;
            /* code */
        }
    }
    else
    {
        while(temp<=MAX-1)
        {
            cout<<" "<<deque[temp];
            temp++;
        }
        temp=0;
        while(temp<=rear)
        {
            cout<<" "<<deque[temp];
            temp++;
        }
    }
    cout<<"\n";
}

int main() {
    int choice, data;
    while(1)
    {
        cout<<"1.Insert at front"<<endl;
        cout<<"2.Insert at rear"<<endl;
        cout<<"3.Delete at front"<<endl;
        cout<<"4.Delete at rear"<<endl;
        cout<<"5.Print the first element"<<endl;
        cout<<"6.Print all the elements"<<endl;
        cout<<"7.Quit"<<endl;
        cout<<" --------------------------- "<<endl;
        cout<<"Enter your choice ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                cout<<" Enter the element to enqueue at front"<<endl;
                cin>>data;
                enqueueFront( data);
                cout<<data<<" Enqued to the front!"<<endl;
                break;
            case 2:
                cout<<" Enter the element to enqueue at rear"<<endl;
                cin>>data;
                enqueueRear( data);
                cout<<data<<" enqued at the rear!"<<endl;
                break;
            case 3:
                cout<<dequeueFront()<<" removed from the front of queue"<<endl;
                break;
            case 4:
                cout<<dequeueRear()<<" removed from the front of queue"<<endl;
                break;
            case 5:
                cout<<peek()<<" is the First Element."<<endl;
                break;
            case 6:
                cout<<"All the elements are :";
                print();
                cout<<endl;
                break;
            case 7:
                exit(1);
                break;
            default:
                cout<<"Give valid response";
        }
    }
    return 0;
}