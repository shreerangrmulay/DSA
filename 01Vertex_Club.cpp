#include <iostream>
#include <string.h>
using namespace std;

struct Node1 {
    int Prn1;
    string Name1;
    string Div1;
    struct Node1* next1;
    int loc1;
};

struct Node2 {
    int Prn2;
    string Name2;
    string Div2;
    struct Node2* next2;
    int loc2;
};

// ---------------- Division 1 ----------------
struct Node1* insertAtBegin(struct Node1* head1, int Prn, string Name, string Div) {
    struct Node1* temp = new Node1;
    temp->Prn1 = Prn;
    temp->Name1 = Name;
    temp->Div1 = Div;
    temp->next1 = head1;
    head1 = temp;
    return head1;
}

struct Node1* insertAtEnd(struct Node1* head1, int Prn, string Name, string Div) {
    struct Node1* temp = new Node1;
    temp->Prn1 = Prn;
    temp->Name1 = Name;
    temp->Div1 = Div;
    temp->next1 = NULL;

    if (head1 == NULL) return temp;

    struct Node1* p = head1;
    while (p->next1 != NULL) p = p->next1;
    p->next1 = temp;
    return head1;
}

void display(struct Node1* head1) {
    struct Node1* p = head1;
    if (!p) { cout << "List 1 empty!\n"; return; }
    while (p != NULL) {
        cout << "PRN : " << p->Prn1 << " | Name : " << p->Name1 << " | Div : " << p->Div1 << endl;
        p = p->next1;
    }
}

int countMembers(struct Node1* head1) {
    int cnt = 0;
    while (head1) { cnt++; head1 = head1->next1; }
    return cnt;
}

struct Node1* deleteAtLoc(struct Node1* head1, int loc1) {
    if (head1 == nullptr) {
        cout << "List is empty!" << endl;
        return head1;
    }
    if (loc1 == 1) {
        Node1* temp = head1;
        head1 = head1->next1;
        delete temp;
        return head1;
    }
    Node1* temp = head1;
    for (int i = 1; temp != nullptr && i < loc1 - 1; i++) {
        temp = temp->next1;
    }
    if (temp == nullptr || temp->next1 == nullptr) {
        cout << "Position out of range!" << endl;
        return head1;
    }
    Node1* nodeToDelete = temp->next1;
    temp->next1 = nodeToDelete->next1;
    delete nodeToDelete;
    return head1;
}

struct Node1* concatenate(struct Node1* head1, struct Node2* head2) {
    if (head1 == NULL) {
        while (head2) {
            head1 = insertAtEnd(head1, head2->Prn2, head2->Name2, head2->Div2);
            head2 = head2->next2;
        }
        return head1;
    }
    struct Node1* p = head1;
    while (p->next1) p = p->next1;
    while (head2) {
        p->next1 = new Node1{head2->Prn2, head2->Name2, head2->Div2, NULL};
        p = p->next1;
        head2 = head2->next2;
    }
    return head1;
}

struct Node1* reverse(struct Node1* head1) {
    Node1* prev = NULL;
    Node1* curr = head1;
    Node1* next = NULL;
    while (curr) {
        next = curr->next1;
        curr->next1 = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void search(struct Node1* head1, int prn) {
    int pos = 1;
    while (head1) {
        if (head1->Prn1 == prn) {
            cout << "Found PRN " << prn << " at position " << pos << endl;
            return;
        }
        head1 = head1->next1;
        pos++;
    }
    cout << "PRN " << prn << " not found!\n";
}

struct Node1* sortByPRN(struct Node1* head1) {
    if (!head1) return head1;
    bool swapped;
    do {
        swapped = false;
        Node1* p = head1;
        while (p->next1) {
            if (p->Prn1 > p->next1->Prn1) {
                swap(p->Prn1, p->next1->Prn1);
                swap(p->Name1, p->next1->Name1);
                swap(p->Div1, p->next1->Div1);
                swapped = true;
            }
            p = p->next1;
        }
    } while (swapped);
    return head1;
}

// ---------------- Division 2 ----------------
struct Node2* insertAtBegin(struct Node2* head2, int Prn, string Name, string Div) {
    struct Node2* temp = new Node2;
    temp->Prn2 = Prn;
    temp->Name2 = Name;
    temp->Div2 = Div;
    temp->next2 = head2;
    head2 = temp;
    return head2;
}

struct Node2* insertAtEnd(struct Node2* head2, int Prn, string Name, string Div) {
    struct Node2* temp = new Node2;
    temp->Prn2 = Prn;
    temp->Name2 = Name;
    temp->Div2 = Div;
    temp->next2 = NULL;

    if (head2 == NULL) return temp;

    struct Node2* p = head2;
    while (p->next2 != NULL) p = p->next2;
    p->next2 = temp;
    return head2;
}

void display(struct Node2* head2) {
    struct Node2* p = head2;
    if (!p) { cout << "List 2 empty!\n"; return; }
    while (p != NULL) {
        cout << "PRN : " << p->Prn2 << " | Name : " << p->Name2 << " | Div : " << p->Div2 << endl;
        p = p->next2;
    }
}

int countMembers(struct Node2* head2) {
    int cnt = 0;
    while (head2) { cnt++; head2 = head2->next2; }
    return cnt;
}

struct Node2* deleteAtLoc(struct Node2* head2, int loc2) {
    if (head2 == nullptr) {
        cout << "List is empty!" << endl;
        return head2;
    }
    if (loc2 == 1) {
        Node2* temp = head2;
        head2 = head2->next2;
        delete temp;
        return head2;
    }
    Node2* temp = head2;
    for (int i = 1; temp != nullptr && i < loc2 - 1; i++) {
        temp = temp->next2;
    }
    if (temp == nullptr || temp->next2 == nullptr) {
        cout << "Position out of range!" << endl;
        return head2;
    }
    Node2* nodeToDelete = temp->next2;
    temp->next2 = nodeToDelete->next2;
    delete nodeToDelete;
    return head2;
}

// ---------------- MAIN ----------------
int main() {
    int Prn, loc, choice;
    string Name, Div;
    struct Node1* head1 = NULL;
    struct Node2* head2 = NULL;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Insert President (List 1)\n";
        cout << "2. Insert Member/Secretary (List 1)\n";
        cout << "3. Insert President (List 2)\n";
        cout << "4. Insert Member/Secretary (List 2)\n";
        cout << "5. Display List 1\n";
        cout << "6. Display List 2\n";
        cout << "7. Delete from List 1\n";
        cout << "8. Delete from List 2\n";
        cout << "9. Concatenate List 1 and List 2\n";
        cout << "10. Count Members (List 1 & 2)\n";
        cout << "11. Reverse List 1\n";
        cout << "12. Search by PRN in List 1\n";
        cout << "13. Sort List 1 by PRN\n";
        cout << "14. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter PRN, Name, Div: ";
                cin >> Prn;
                cin.ignore();
                getline(cin, Name);
                getline(cin, Div);
                head1 = insertAtBegin(head1, Prn, Name, Div);
                break;
            case 2:
                cout << "Enter PRN, Name, Div: ";
                cin >> Prn;
                cin.ignore();
                getline(cin, Name);
                getline(cin, Div);
                head1 = insertAtEnd(head1, Prn, Name, Div);
                break;
            case 3:
                cout << "Enter PRN, Name, Div: ";
                cin >> Prn;
                cin.ignore();
                getline(cin, Name);
                getline(cin, Div);
                head2 = insertAtBegin(head2, Prn, Name, Div);
                break;
            case 4:
                cout << "Enter PRN, Name, Div: ";
                cin >> Prn;
                cin.ignore();
                getline(cin, Name);
                getline(cin, Div);
                head2 = insertAtEnd(head2, Prn, Name, Div);
                break;
            case 5: display(head1); break;
            case 6: display(head2); break;
            case 7:
                cout << "Enter position to delete in List 1: ";
                cin >> loc;
                head1 = deleteAtLoc(head1, loc);
                break;
            case 8:
                cout << "Enter position to delete in List 2: ";
                cin >> loc;
                head2 = deleteAtLoc(head2, loc);
                break;
            case 9:
                head1 = concatenate(head1, head2);
                cout << "Lists concatenated into List 1.\n";
                display(head1);
                break;
            case 10:
                cout << "List 1 Members: " << countMembers(head1) << endl;
                cout << "List 2 Members: " << countMembers(head2) << endl;
                break;
            case 11:
                head1 = reverse(head1);
                cout << "List 1 reversed.\n";
                break;
            case 12:
                cout << "Enter PRN to search in List 1: ";
                cin >> Prn;
                search(head1, Prn);
                break;
            case 13:
                head1 = sortByPRN(head1);
                cout << "List 1 sorted.\n";
                break;
            case 14:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 14);

    return 0;
}
