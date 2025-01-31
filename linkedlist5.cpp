#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
    }
    ~Node() {
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
    }
};

void insertNode(Node*& tail, int element, int data) {
    // If the list is empty
    if (tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    } else {
        // Find the node with the given element
        Node* curr = tail;

        while (curr->data != element) {
            curr = curr->next;

            // To prevent infinite loops, we should check if we've gone full circle
            if (curr == tail) {
                cout << "Element " << element << " not found in the list. Insertion aborted." << endl;
                return;
            }
        }

        // Insert the new node after the found node
        Node* temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void print(Node* tail) {
    if (tail == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = tail;

    do {
        cout << tail->data << " ";
        tail = tail->next;
    } while (tail != temp);

    cout << endl;
}

int main() {
    Node* tail = NULL;

    insertNode(tail, 5, 3);
    print(tail);

    insertNode(tail, 3, 5);
    print(tail);

    insertNode(tail, 7, 10);
    print(tail);

    return 0;
}
