void preorder(node* root)
{

    if(root==nullptr)
    {  
        cout<<"Empty tree";
        exit(1);
    }

    node* ptr=root;
    push(ptr);
    while(!isEmpty())
    {
        ptr=pop();
        cout<<ptr->data;
        if(ptr->right!=nullptr)
            push(ptr->right)
        else(ptr->left !=nullptr)
            push(ptr->left)
    }
}