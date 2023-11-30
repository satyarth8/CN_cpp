#include <iostream>
using namespace std;
struct node{
    int data;
     node* next;
};

node* addToEmpty(node* tail,int data)
{
    node* temp= new node;
    temp->data=data;
    temp->next=temp;
    return temp;
}
node* add_at_beg(node* tail, int value)
{
    node* temp=new node;
    temp->next=tail->next;
    temp->data=value;
    tail->next=temp;
    return tail;
}
node* add_at_end(node* tail, int value)
{
    node* temp= new node;
    temp->data=value;
    temp->next=tail->next;
    tail->next=temp;
    tail=temp;
    return tail;// temp is the new end so we can return temp too
}
int find_index(node* tail, int val)
{
    int index=0;
    node* temp=tail->next;
    do{
        if(temp->data==val)
        {
            return index;
        }
        index++;
        temp=temp->next;
    }while(temp!=temp->next);
    return -1;
}
void print(node* tail)
{
    node* ptr = tail->next;
    do {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != tail->next);

    cout << endl;

}
int main() {
    int n, val;
    node* tail = new node;

    cout << "Enter the number of elements you want: ";
    cin >> n;

    cout << "Enter the value to be added: ";
    cin >> val;
    tail = addToEmpty(tail, val);
    for (int i = 1; i <n; i++) 
    {
        cout << "Enter the value to be added : ";
        cin >> val;
        tail = add_at_end(tail, val);
    }
    cout << "Circular Linked List:" << endl;
    
    print(tail);
    int find_val;
    cout<<"Enter the value you want to find :";
    cin>>find_val;
    cout<<"Value found at index :"<<find_index(tail,find_val);
    return 0;
    return 0;
}