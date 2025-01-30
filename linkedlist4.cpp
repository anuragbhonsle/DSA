#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    if(head == NULL){
        Node* temp = new Node(d);
        head = temp;
    }else{
        Node* temp = new Node(d);
        temp -> next = head;
        head -> prev = temp;
        head = temp;
    }
}

void insertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;

}

void print(Node* head){
    Node* temp = head;
    
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int getLength(Node* head){
    Node* temp = head;
    
    int len = 0;
    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtPosition(Node* &tail, Node* &head, int position, int data){

    if(position == 1){
        insertAtHead(head, data);
        return ;
    }

    int cnt = 1;
    Node* temp = head;

    while(cnt < position-1){
        temp = temp ->next;
        cnt++;
    }
    if (temp -> next == NULL) {
        insertAtTail(tail, data);
        return ;
    }

    Node* nodetoinsert = new Node(data);
    nodetoinsert -> next = temp -> next;
    temp -> next -> prev = nodetoinsert;
    temp -> next = nodetoinsert;
    nodetoinsert -> prev = temp;

}

int main(){

Node* node1 = new Node(10);
Node* head = node1;
Node* tail = head;
//print(head);
//cout << getLength(head) << endl; 
insertAtHead(head, 20);
insertAtHead(head, 30);
cout << endl;
//print(head);
insertAtTail(tail, 69); 
insertAtPosition(tail, head, 4, 77);
print(head);
}