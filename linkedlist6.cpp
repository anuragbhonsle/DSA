#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int data){
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}
void print(Node* head){

Node* temp = head;

while(temp != NULL){
    cout << temp-> data << " ";
    temp = temp -> next; 
}
cout << " ";
}

void reverseList(Node* &head) {
    if (head == NULL || head->next == NULL) {
        return; 
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;

    while (curr != NULL) {
        forward = curr -> next; 
        curr -> next = prev;    
        prev = curr;          
        curr = forward;       
    }

    head = prev;
}

void reverseList2(Node* &head, Node* curr, Node* prev){
    //base case
    if(curr == NULL){
        head = prev;
        return;
    }

    Node* forward = curr -> next;
    reverseList2(head, forward, curr);
    curr -> next = prev;
}

int main(){
Node* node1 = new Node(3);
Node* head = node1;
insertAtHead(head, 6);
insertAtHead(head, 9);
print(head);
cout << endl;
Node* curr = head;
Node* prev = NULL;
reverseList2(head, curr, prev);
print(head);
}