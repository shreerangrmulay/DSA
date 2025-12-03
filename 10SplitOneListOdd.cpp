#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;
    return newNode;
}

void append(Node*& head, int val) {
    Node* newNode = createNode(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void displayList(Node* head) {
    Node* temp = head;
    cout << "{";
    while (temp) {
        cout << temp->data;
        if (temp->next) cout << ", ";
        temp = temp->next;
    }
    cout << "}" << endl;
}


void FrontBackSplit(Node* source, Node*& front, Node*& back) {
    if (!source) {
        front = nullptr;
        back = nullptr;
        return;
    }
    if (!source->next) {
        front = source;
        back = nullptr;
        return;
    }

    Node* slow = source;
    Node* fast = source->next;

    while (fast) {
        fast = fast->next;
        if (fast) {
            fast = fast->next;
            slow = slow->next;
        }
    }

    front = source;
    back = slow->next;
    slow->next = nullptr;
}

int main() {
    Node* head = nullptr;

    append(head, 2);
    append(head, 3);
    append(head, 5);
    append(head, 7);
    append(head, 11);

    cout << "Original list: ";
    displayList(head);

    Node* front = nullptr;
    Node* back = nullptr;

    FrontBackSplit(head, front, back);

    cout << "Front list: ";
    displayList(front);

    cout << "Back list: ";
    displayList(back);

    Node* test1 = nullptr; 
    append(test1, 1);
    append(test1, 2);
    Node* f1 = nullptr; Node* b1 = nullptr;
    FrontBackSplit(test1, f1, b1);
    cout << "Length 2 test: Front "; displayList(f1); cout << "Back "; displayList(b1);

    Node* test2 = nullptr; 
    append(test2, 1); append(test2, 2); append(test2, 3);
    Node* f2 = nullptr; Node* b2 = nullptr;
    FrontBackSplit(test2, f2, b2);
    cout << "Length 3 test: Front "; displayList(f2); cout << "Back "; displayList(b2);

    Node* test3 = nullptr; 
    append(test3, 1); append(test3, 2); append(test3, 3); append(test3, 4);
    Node* f3 = nullptr; Node* b3 = nullptr;
    FrontBackSplit(test3, f3, b3);
    cout << "Length 4 test: Front "; displayList(f3); cout << "Back "; displayList(b3);

    return 0;
}
