#include <iostream>
using namespace std;

struct Node {
    int bit;
    Node* prev;
    Node* next;
};

class BinaryNumber {
    Node* head;
    Node* tail;

public:
    BinaryNumber() {
        head = tail = nullptr;
    }

    void insertBit(int b) {
        Node* newNode = new Node{b, nullptr, nullptr};
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->bit;
            temp = temp->next;
        }
        cout << endl;
    }

    // Create 1's complement
    BinaryNumber onesComplement() {
        BinaryNumber result;
        Node* temp = head;
        while (temp) {
            result.insertBit(temp->bit == 0 ? 1 : 0);
            temp = temp->next;
        }
        return result;
    }

    BinaryNumber twosComplement() {
        BinaryNumber oneComp = onesComplement();
        BinaryNumber result;
        Node* temp = oneComp.tail;
        int carry = 1;

        while (temp) {
            int sum = temp->bit + carry;
            result.insertFront(sum % 2);
            carry = sum / 2;
            temp = temp->prev;
        }
        if (carry) result.insertFront(carry);

        return result;
    }

    void insertFront(int b) {
        Node* newNode = new Node{b, nullptr, nullptr};
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    static BinaryNumber add(BinaryNumber& A, BinaryNumber& B) {
        BinaryNumber result;
        Node* p = A.tail;
        Node* q = B.tail;
        int carry = 0;

        while (p || q || carry) {
            int sum = carry;
            if (p) { sum += p->bit; p = p->prev; }
            if (q) { sum += q->bit; q = q->prev; }

            result.insertFront(sum % 2);
            carry = sum / 2;
        }
        return result;
    }
};

int main() {
    BinaryNumber num1, num2;

    int n, bit;
    cout << "Enter number of bits in first binary number: ";
    cin >> n;
    cout << "Enter bits (MSB to LSB): ";
    for (int i = 0; i < n; i++) {
        cin >> bit;
        num1.insertBit(bit);
    }

    cout << "First binary number: ";
    num1.display();

    cout << "1's Complement: ";
    BinaryNumber ones = num1.onesComplement();
    ones.display();

    cout << "2's Complement: ";
    BinaryNumber twos = num1.twosComplement();
    twos.display();

    cout << "\nEnter number of bits in second binary number: ";
    cin >> n;
    cout << "Enter bits (MSB to LSB): ";
    for (int i = 0; i < n; i++) {
        cin >> bit;
        num2.insertBit(bit);
    }

    cout << "Second binary number: ";
    num2.display();

    cout << "Addition Result: ";
    BinaryNumber sum = BinaryNumber::add(num1, num2);
    sum.display();

    return 0;
}
