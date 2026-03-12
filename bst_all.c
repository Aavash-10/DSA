// BST in C

#include <stdio.h>
#include <stdlib.h>   // It is required for malloc() and exit()

//First we need to create a new node

// Creating a new BST node
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

// This is Function to create a new node
Node* newNode(int key) {
    Node *n = (Node*)malloc(sizeof(Node));
    
    if (!n) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    n->key = key;
    n->left = NULL;
    n->right = NULL;

    return n;
}

//Then for every key inserted we enter it in either left or right

// It is Code to Attach key to left or right child if possible
int attach_to_immediate_child(Node *node, int key) {

    if (node == NULL)
        return 0;

    if (key < node->key) {
        if (node->left == NULL) {
            node->left = newNode(key);
            return 1;   // attached to left
        } else {
            return -1;  // left occupied
        }
    }

    else if (key > node->key) {
        if (node->right == NULL) {
            node->right = newNode(key);
            return 2;   // attached to right
        } else {
            return -2;  // right occupied
        }
    }

    else {
        //duplicate key;decide your policy(ignore here)
        return -3;      // duplicate key
    }
}

//This is BST insertion using traversal
void insert(Node *root, int key) {

    Node *current = root;

    while (1) {

        int result = attach_to_immediate_child(current, key);

        if (result == 1 || result == 2) {
            //attached successfully
            return; // inserted successfully
        }

        else if (result == -1) {
            current = current->left;
        }

        else if (result == -2) {
            current = current->right;
        }

        else if (result == -3) {
            printf("Duplicate key ignored: %d\n", key);
            return;
        }
    }
}

// Inorder traversal (It is used to verify BST)
void inorder(Node *root) {

    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}

// Preorder traversal
void preorder(Node *root) {

    if (root == NULL)
        return;

    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(Node *root) {

    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

int main() {

    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(keys) / sizeof(keys[0]);

    // first element becomes root
    Node *root = newNode(keys[0]);

    // insert remaining keys
    for (int i = 1; i < n; i++) {
        insert(root, keys[i]);
    }

    printf("Inorder traversal of BST:\n");
    inorder(root);

    printf("\n\nPreorder traversal of BST:\n");
    preorder(root);

    printf("\n\nPostorder traversal of BST:\n");
    postorder(root);

    return 0;
}