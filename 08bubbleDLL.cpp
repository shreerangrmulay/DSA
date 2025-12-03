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

void insertEnd(Node*& head, int val) {
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

void displayList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << " <-> ";
        temp = temp->next;
    }
    cout << endl;
}

void bubbleSort(Node* head) {
    if (!head) return;
    bool swapped;
    Node* ptr;
    Node* last = nullptr;

    do {
        swapped = false;
        ptr = head;

        while (ptr->next != last) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = true;
            }
            ptr = ptr->next;
        }
        last = ptr; 
    } while (swapped);
}

int main() {
    Node* head = nullptr;

    insertEnd(head, 5);
    insertEnd(head, 1);
    insertEnd(head, 4);
    insertEnd(head, 2);
    insertEnd(head, 3);

    cout << "Original List: ";
    displayList(head);

    bubbleSort(head);

    cout << "Sorted List: ";
    displayList(head);

    return 0;
}
