#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
};

Node* createNode(int c, int e) {
    Node* newNode = new Node;
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = nullptr;
    return newNode;
}

void insertEnd(Node*& head, int c, int e) {
    Node* newNode = createNode(c, e);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void displayPolynomial(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->coeff << "x^" << temp->exp;
        if (temp->next) cout << " + ";
        temp = temp->next;
    }
    cout << endl;
}

Node* addPolynomials(Node* p1, Node* p2) {
    Node* result = nullptr;
    Node *t1 = p1, *t2 = p2;

    while (t1 && t2) {
        if (t1->exp > t2->exp) {
            insertEnd(result, t1->coeff, t1->exp);
            t1 = t1->next;
        } else if (t1->exp < t2->exp) {
            insertEnd(result, t2->coeff, t2->exp);
            t2 = t2->next;
        } else {
            int sumCoeff = t1->coeff + t2->coeff;
            if (sumCoeff != 0) insertEnd(result, sumCoeff, t1->exp);
            t1 = t1->next;
            t2 = t2->next;
        }
    }

    while (t1) {
        insertEnd(result, t1->coeff, t1->exp);
        t1 = t1->next;
    }
    while (t2) {
        insertEnd(result, t2->coeff, t2->exp);
        t2 = t2->next;
    }

    return result;
}

int main() {
    Node* poly1 = nullptr;
    Node* poly2 = nullptr;

    insertEnd(poly1, 5, 3);
    insertEnd(poly1, 4, 2);
    insertEnd(poly1, 2, 0);

    insertEnd(poly2, 3, 3);
    insertEnd(poly2, 2, 1);
    insertEnd(poly2, 1, 0);

    cout << "Polynomial 1: ";
    displayPolynomial(poly1);

    cout << "Polynomial 2: ";
    displayPolynomial(poly2);

    Node* sum = addPolynomials(poly1, poly2);
    cout << "Sum: ";
    displayPolynomial(sum);

    return 0;
}
