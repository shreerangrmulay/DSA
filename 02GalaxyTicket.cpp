#include <iostream>
using namespace std;

struct Seat {
    int seatNo;     // seat number (1-8)
    bool booked;    // 0 = available, 1 = booked
    Seat* next;
    Seat* prev;
};

// Create a doubly circular linked list for each row
Seat* createRow(int seats) {
    Seat* head = nullptr;
    Seat* temp = nullptr;
    for (int i = 1; i <= seats; i++) {
        Seat* newSeat = new Seat;
        newSeat->seatNo = i;
        newSeat->booked = (rand() % 2); // random booking initially
        newSeat->next = nullptr;
        newSeat->prev = nullptr;

        if (!head) {
            head = newSeat;
            temp = head;
        } else {
            temp->next = newSeat;
            newSeat->prev = temp;
            temp = newSeat;
        }
    }
    // Make it circular
    temp->next = head;
    head->prev = temp;

    return head;
}

// Display all seats in multiplex
void display(Seat* head, int row) {
    if (!head) return;
    Seat* temp = head;
    cout << "Row " << row + 1 << ": ";
    do {
        if (temp->booked)
            cout << "[X] "; // booked
        else
            cout << "[" << temp->seatNo << "] "; // available
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Book a seat
void bookSeat(Seat* head, int seatNo) {
    Seat* temp = head;
    do {
        if (temp->seatNo == seatNo) {
            if (temp->booked) {
                cout << "❌ Seat " << seatNo << " is already booked.\n";
            } else {
                temp->booked = true;
                cout << "✅ Seat " << seatNo << " booked successfully!\n";
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

// Cancel a booking
void cancelSeat(Seat* head, int seatNo) {
    Seat* temp = head;
    do {
        if (temp->seatNo == seatNo) {
            if (!temp->booked) {
                cout << "❌ Seat " << seatNo << " is not booked.\n";
            } else {
                temp->booked = false;
                cout << "✅ Seat " << seatNo << " booking cancelled.\n";
            }
            return;
        }
        temp = temp->next;
    } while (temp != head);
}

int main() {
    const int rows = 8, seats = 8;
    Seat* multiplex[rows];

    // Create 8 rows
    for (int i = 0; i < rows; i++) {
        multiplex[i] = createRow(seats);
    }

    int choice, row, seat;
    do {
        cout << "\n Galaxy Multiplex Reservation System \n";
        cout << "1. Display available seats\n";
        cout << "2. Book a seat\n";
        cout << "3. Cancel a booking\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < rows; i++) {
                    display(multiplex[i], i);
                }
                break;

            case 2:
                cout << "Enter row (1-8): ";
                cin >> row;
                cout << "Enter seat number (1-8): ";
                cin >> seat;
                if (row >= 1 && row <= rows)
                    bookSeat(multiplex[row - 1], seat);
                else
                    cout << "Invalid row!\n";
                break;

            case 3:
                cout << "Enter row (1-8): ";
                cin >> row;
                cout << "Enter seat number (1-8): ";
                cin >> seat;
                if (row >= 1 && row <= rows)
                    cancelSeat(multiplex[row - 1], seat);
                else
                    cout << "Invalid row!\n";
                break;

            case 4:
                cout << "Exiting... Thank you!\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}
