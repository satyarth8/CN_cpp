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


struct node* case1( node* root, node* ptr, node* par)
{
    if(par==nullptr)
        root=nullptr;
    else if(ptr==par->left)
        par->left=nullptr;
    else
        par->right=nullptr;
    free(ptr);
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

    if (ptr->left == nullptr && ptr->right == nullptr) {
        root = case1(root, ptr, par);
    }

    return root;
}


int main() {
    struct node* root = nullptr;
    int arr[7] = {67, 34, 80, 10, 55, 45, 60};
    for (int i = 0; i < 7; i++) {
        root = insert_Rec(root, arr[i]);
    }
    cout << "Before Deletion" << endl;
    printBST(root);

    root = del_nonRec(root, 80);
    cout << endl << "After Deletion" << endl;
    printBST(root);

    return 0;
}
