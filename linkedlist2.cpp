#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* nextNode;

    Node(int data){
        this -> data = data;
        this -> nextNode = NULL;
    }
};

void insertAtStart(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> nextNode = head;
    head = temp;
}
void insertAtEnd(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> nextNode = temp;
    tail = temp;
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp ->data << " ";
        temp = temp -> nextNode;
    }
}




int main(){
Node* node1 = new Node(23);
Node* head = node1;
Node* tail = node1;
insertAtEnd(tail, 5);
insertAtEnd(tail, 7);
insertAtEnd(tail, 8);
print(head);
}