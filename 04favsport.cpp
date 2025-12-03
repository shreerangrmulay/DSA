#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* insert(Node* head, int val) {
    Node* newNode = new Node{val, nullptr};
    if (!head) return newNode;

    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    return head;
}

void display(Node* head) {
    Node* temp = head;
    cout << "{ ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "}" << endl;
}

bool exists(Node* head, int val) {
    Node* temp = head;
    while (temp) {
        if (temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}

Node* intersection(Node* A, Node* B) {
    Node* result = nullptr;
    Node* temp = A;
    while (temp) {
        if (exists(B, temp->data)) {
            result = insert(result, temp->data);
        }
        temp = temp->next;
    }
    return result;
}

Node* symmetricDifference(Node* A, Node* B) {
    Node* result = nullptr;
    Node* temp = A;

    // Elements in A but not in B
    while (temp) {
        if (!exists(B, temp->data))
            result = insert(result, temp->data);
        temp = temp->next;
    }

    temp = B;
    while (temp) {
        if (!exists(A, temp->data))
            result = insert(result, temp->data);
        temp = temp->next;
    }

    return result;
}

int countNeither(Node* U, Node* A, Node* B) {
    int count = 0;
    Node* temp = U;
    while (temp) {
        if (!exists(A, temp->data) && !exists(B, temp->data)) {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

int main() {
    Node *A = nullptr, *B = nullptr, *U = nullptr;
    int n, m, total, x;

    cout << "Enter total number of students in class: ";
    cin >> total;
    cout << "Enter roll numbers of all students:\n";
    for (int i = 0; i < total; i++) {
        cin >> x;
        U = insert(U, x);
    }

    cout << "Enter number of students who like Cricket: ";
    cin >> n;
    cout << "Enter their roll numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        A = insert(A, x);
    }

    cout << "Enter number of students who like Football: ";
    cin >> m;
    cout << "Enter their roll numbers:\n";
    for (int i = 0; i < m; i++) {
        cin >> x;
        B = insert(B, x);
    }

    cout << "\nSet A (Cricket): ";
    display(A);
    cout << "Set B (Football): ";
    display(B);

    cout << "\na) Students who like BOTH Cricket and Football: ";
    Node* both = intersection(A, B);
    display(both);

    cout << "b) Students who like EITHER Cricket OR Football but NOT both: ";
    Node* either = symmetricDifference(A, B);
    display(either);
   
    cout << "c) Number of students who like NEITHER Cricket nor Football: ";
    cout << countNeither(U, A, B) << endl;

    return 0;
}
