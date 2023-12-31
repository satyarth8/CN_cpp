struct node* case1(struct node* root, struct node* delNode, struct node* parent) 
{
    // Check if the node to be deleted is the root
    if (parent == nullptr) {
        free(delNode);
        return nullptr; // Tree is now empty
    }

    // Determine whether the node to be deleted is the left or right child of its parent
    if (delNode == parent->left)
        parent->left = nullptr;
    else
        parent->right = nullptr;

    free(delNode); // Free the memory of the node to be deleted

    return root; // Return the updated root
}