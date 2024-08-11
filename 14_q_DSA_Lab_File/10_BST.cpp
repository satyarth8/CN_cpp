#include <iostream>

using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node* insert(Node *node, int data) {
  if (node == nullptr) {
    node = new Node;
    node->data = data;
    node->left = node->right = NULL;
  } else if (data < node->data) {
    node->left = insert(node->left, data);
  } else if (data > node->data) {
    node->right = insert(node->right, data);
  }
  return node;
}

Node* search(Node *node, int data) {
  if (node == NULL || node->data == data) {
    return node;
  } else if (data < node->data) {
    return search(node->left, data);
  } else {
    return search(node->right, data);
  }
}

Node* find_min(Node *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

Node* delete_node(Node *node, int data) {
  if (node == NULL) {
    return NULL;
  } else if (data < node->data) {
    node->left = delete_node(node->left, data);
  } else if (data > node->data) {
    node->right = delete_node(node->right, data);
  } else {
    // Node with one or no children
    if (node->left == NULL) {
      Node *temp = node->right;
      delete node;
      return temp;
    } else if (node->right == NULL) {
      Node *temp = node->left;
      delete node;
      return temp;
    }

    // Node with two children
    Node *temp = find_min(node->right);
    node->data = temp->data;
    node->right = delete_node(node->right, temp->data);
  }
  return node;
}

void inorder_traversal(Node *node) {
  if (node != NULL) {
    inorder_traversal(node->left);
    cout << node->data << " ";
    inorder_traversal(node->right);
  }
}

int main() {
  Node *root = NULL;

  root = insert(root, 50);
  root = insert(root, 30);
  root = insert(root, 20);
  root = insert(root, 40);
  root = insert(root, 70);
  root = insert(root, 60);
  root = insert(root, 80);

  cout << "Inorder traversal: ";
  inorder_traversal(root);
  cout << endl;

  Node *searched_node = search(root, 20);
  if (searched_node != NULL) {
    cout << "Node with value 20 found." << endl;
  } else {
    cout << "Node with value 20 not found." << endl;
  }

  root = delete_node(root, 20);

  cout << "Inorder traversal after deleting 20: ";
  inorder_traversal(root);
  cout << endl;

  return 0;
}