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
    ~Node(){
        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }
    }
};

void insertAtStart(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtEnd(Node* &tail, int data){
    Node* temp = new Node(data);
    tail -> next = temp;
    tail = temp;
}
void insertAtPosition(Node* &tail, Node* &head, int position, int data){

    if(position == 1){
        insertAtStart(head, data);
        return ;
    }

    int cnt = 1;
    Node* temp = head;

    while(cnt < position-1){
        temp = temp ->next;
        cnt++;
    }
    if (temp -> next == NULL) {
        insertAtEnd(tail, data);
        return ;
    }

    Node* nodetoinsert = new Node(data);
    nodetoinsert ->next = temp -> next;
    temp -> next = nodetoinsert;
}
void deleteNode(Node* &head, int position){

    if(position == 1){
        Node* temp = head;
        head = head ->next;
        temp -> next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;
        int count = 1; 
        while(count < position){
            prev = curr;
            curr = curr-> next;
             count++;
        }
        prev -> next = curr->next;
        curr -> next = NULL;
        delete curr;
    }

}
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp ->data << " ";
        temp = temp ->next;
    }     
}

int main(){
Node* node1 = new Node(7);
Node* head = node1;
//Node* tail = node1;

insertAtStart(head, 8);
insertAtStart(head, 9);
insertAtStart(head, 10);
insertAtStart(head, 11);
//insertAtEnd(tail, 14);
//insertAtEnd(tail, 21);
//insertAtPosition(tail, head, 4, 99);
cout << endl;
print(head);
deleteNode(head, 5);
cout << endl;
print(head);
cout << endl;
}