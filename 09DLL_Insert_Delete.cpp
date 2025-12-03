#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
    Node* prev;
};


Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}


void insertAtBeginning(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}


void insertAtEnd(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}


void insertAtPosition(Node*& head, int val, int pos) {
    if (pos == 1) {
        insertAtBeginning(head, val);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp; i++)
        temp = temp->next;

    if (!temp) {
        cout << "Position out of bounds!" << endl;
        return;
    }

    Node* newNode = createNode(val);
    newNode->next = temp->next;
    if (temp->next) temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}


void deleteAtBeginning(Node*& head) {
    if (!head) return;
    Node* temp = head;
    head = head->next;
    if (head) head->prev = nullptr;
    delete temp;
}


void deleteAtEnd(Node*& head) {
    if (!head) return;
    Node* temp = head;
    if (!temp->next) { 
        delete temp;
        head = nullptr;
        return;
    }
    while (temp->next) temp = temp->next;
    temp->prev->next = nullptr;
    delete temp;
}

void deleteAtPosition(Node*& head, int pos) { 
    if (!head) return;
    if (pos == 1) {
        deleteAtBeginning(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos && temp; i++)
        temp = temp->next;
    if (!temp) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    if (temp->next) temp->next->prev = temp->prev;
    if (temp->prev) temp->prev->next = temp->next;
    delete temp;
}


void displayList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    Node* head = nullptr;


    insertAtEnd(head, 10);
    insertAtBeginning(head, 5);
    insertAtEnd(head, 20);
    insertAtPosition(head, 15, 3); 

    cout << "List after insertions: ";
    displayList(head);

  
    deleteAtBeginning(head);
    cout << "List after deleting at beginning: ";
    displayList(head);

    deleteAtEnd(head);
    cout << "List after deleting at end: ";
    displayList(head);

    deleteAtPosition(head, 2); 
    cout << "List after deleting at position 2: ";
    displayList(head);

    return 0;
}
