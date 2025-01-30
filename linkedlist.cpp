#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtStart(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;

}
void insertAtPosition(Node* &head, int position, int data){

    if(position == 1){
        insertAtHead(head, data);
        return ;
    }
    int cnt = 1;
    Node* temp = head;
    while(cnt < position){
        temp = temp ->next;
        cnt++;
    }
    Node* nodetoinsert = new Node(data);
    nodetoinsert ->next = temp -> next;
    temp -> next = nodetoinsert;
}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
int main(){

Node* node1 = new Node(23);
Node* head = node1;
insertAtHead(head, 25);
insertAtHead(head, 29);
print(head);
}