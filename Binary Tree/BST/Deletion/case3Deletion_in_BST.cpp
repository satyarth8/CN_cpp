#include <iostream>

using namespace std;

struct node {
    struct node* left;
    int data;
    struct node* right;
};

struct node* createNode(int data) 
{
    node* ptr = new node;
    ptr->left = nullptr;
    ptr->data = data;
    ptr->right = nullptr;
    return ptr;
}

struct node* insert_Rec(struct node* root, int ikey) {
    if (root == nullptr)
        root = createNode(ikey);
    else if (ikey < root->data)
        root->left = insert_Rec(root->left, ikey);
    else if (ikey > root->data)
        root->right = insert_Rec(root->right, ikey);
    else
        cout << "Duplicate Key";
    return root;
}

void printBST(struct node* root) {
    if (root == nullptr)
        return;
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

struct node* case1(node* root, node* ptr, node* par)
{
    if (par == nullptr)
        root = nullptr;
    else if (ptr == par->left)
        par->left = nullptr;
    else
        par->right = nullptr;
    free(ptr);
    return root;
}

struct node* case2(node* root, struct node* ptr, struct node* par)
{
    struct node* child;
    if (ptr->left != nullptr)
        child = ptr->left;
    else if (ptr->right != nullptr)
        child = ptr->right;

    if (par == nullptr)
        root = child;
    else if (ptr == par->left)
        par->left = child;
    else
        par->right = child;
    free(ptr);
    return root;
}

struct node* case3(struct node* root,struct node* ptr)
{
    struct node * successor, *parsuccessor;
    parsuccessor=ptr;
    successor=ptr->right;
    while(successor->left !=nullptr)
        parsuccessor=successor;
        successor=successor->left;
    ptr->data=successor->data;
    if(successor->left==nullptr && successor->right ==nullptr)
        root=case1(root,successor,parsuccessor);
    else
        root=case2(root,successor,parsuccessor);
    return root;
}
struct node* del_nonRec(struct node* root, int dkey) {
    struct node* ptr, *par;
    ptr = root;
    par = nullptr;

    while (ptr != nullptr) {
        if (dkey == ptr->data)
            break;
        par = ptr;
        if (dkey < ptr->data)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if(ptr->left !=nullptr && ptr->right !=nullptr)
        root=case3(root,ptr);
    else if (ptr->left != nullptr || ptr->right != nullptr) {
        root = case2(root, ptr, par);
    }
    else   
        root=case1(root,ptr,par);
    return root;
}

int main() {
    struct node* root = nullptr;
    int arr[7] = {67, 34, 80,10, 55, 45, 60};
    int sizearr = sizeof(arr) / sizeof(arr[0]);
    cout << sizearr;
    for (int i = 0; i < sizearr; i++) {
        root = insert_Rec(root, arr[i]);
    }
    cout << "Before Deletion" << endl;
    printBST(root);

    root = del_nonRec(root, 34);
    cout << endl << "After Deletion" << endl;
    printBST(root);

    return 0;
}
