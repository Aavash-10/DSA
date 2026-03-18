#include <stdio.h>
#include <stdlib.h>

// Create node
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Create new node
Node* newNode(int data) {
    Node *n = (Node*)malloc(sizeof(Node));

    if (!n) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    n->data = data;
    n->next = NULL;

    return n;
}

// 🔹 It is a code to Attach next node using immediate
int attach_to_immediate_next(Node *node, int data) {

    if (node == NULL)
        return 0;

    if (node->next == NULL) {
        node->next = newNode(data);
        return 1;   // new node is attached successfully
    }
    else {
        return -1;  // next is already occupied
    }
}

// 🔹 Insert the node using traversal
void insert(Node *head, int data) {

    Node *current = head;

    while (1) {

        int result = attach_to_immediate_next(current, data);

        if (result == 1) {
            return; // inserted
        }
        else if (result == -1) {
            current = current->next;
        }
    }
}

// Display/traverse the linked list
void display(Node *head) {

    Node *current = head;

    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }

    printf("NULL\n");
}

// Main function
int main() {

    int values[] = {10, 20, 30, 40, 50};
    int n = sizeof(values) / sizeof(values[0]);

    // first element becomes head
    Node *head = newNode(values[0]);

    // insert remaining values
    for (int i = 1; i < n; i++) {
        insert(head, values[i]);
    }

    printf("Linked List:\n");
    display(head);

    return 0;
}