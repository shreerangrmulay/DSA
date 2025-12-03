#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Appointment {
    int start;       // in minutes from midnight
    int end;
    bool booked;
    Appointment* next;
};

// Convert minutes -> HH:MM format
string formatTime(int minutes) {
    int h = minutes / 60;
    int m = minutes % 60;
    char buf[6];
    sprintf(buf, "%02d:%02d", h, m);
    return string(buf);
}

// Create random slots for the day
Appointment* createSchedule(int dayStart, int dayEnd, int minDur, int maxDur) {
    srand(time(0));
    Appointment* head = nullptr;
    Appointment* tail = nullptr;
    int current = dayStart;

    while (current + minDur <= dayEnd) {
        int dur = minDur + rand() % (maxDur - minDur + 1);
        int slotEnd = current + dur;
        if (slotEnd > dayEnd) break;

        Appointment* newAppt = new Appointment{current, slotEnd, false, nullptr};

        if (!head) head = tail = newAppt;
        else {
            tail->next = newAppt;
            tail = newAppt;
        }

        current = slotEnd; // move to next slot
    }
    return head;
}

// Display slots
void display(Appointment* head) {
    Appointment* temp = head;
    int i = 1;
    while (temp) {
        cout << i++ << ". " << formatTime(temp->start) << " - " 
             << formatTime(temp->end)
             << (temp->booked ? " [BOOKED]" : " [AVAILABLE]") << endl;
        temp = temp->next;
    }
}

// Book slot
void book(Appointment* head, int slot) {
    Appointment* temp = head;
    int i = 1;
    while (temp) {
        if (i == slot) {
            if (temp->booked) cout << "❌ Slot already booked!\n";
            else {
                temp->booked = true;
                cout << "✅ Appointment booked at " 
                     << formatTime(temp->start) << " - " 
                     << formatTime(temp->end) << endl;
            }
            return;
        }
        i++;
        temp = temp->next;
    }
    cout << "❌ Invalid slot number!\n";
}

// Cancel booking
void cancel(Appointment* head, int slot) {
    Appointment* temp = head;
    int i = 1;
    while (temp) {
        if (i == slot) {
            if (!temp->booked) cout << "❌ Slot not booked yet!\n";
            else {
                temp->booked = false;
                cout << "✅ Appointment cancelled for " 
                     << formatTime(temp->start) << " - " 
                     << formatTime(temp->end) << endl;
            }
            return;
        }
        i++;
        temp = temp->next;
    }
    cout << "❌ Invalid slot number!\n";
}

// Sort by swapping data
void sortByData(Appointment* head) {
    for (Appointment* i = head; i && i->next; i = i->next) {
        for (Appointment* j = i->next; j; j = j->next) {
            if (i->start > j->start) {
                swap(i->start, j->start);
                swap(i->end, j->end);
                swap(i->booked, j->booked);
            }
        }
    }
    cout << "✅ Sorted (by data)\n";
}

// Sort by pointer manipulation (insertion sort style)
Appointment* sortByPointer(Appointment* head) {
    if (!head || !head->next) return head;

    Appointment* sorted = nullptr;

    while (head) {
        Appointment* curr = head;
        head = head->next;
        if (!sorted || curr->start < sorted->start) {
            curr->next = sorted;
            sorted = curr;
        } else {
            Appointment* temp = sorted;
            while (temp->next && temp->next->start < curr->start) {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
    }
    cout << "✅ Sorted (by pointer manipulation)\n";
    return sorted;
}

int main() {
    int startTime = 9 * 60;   // 9:00
    int endTime   = 17 * 60;  // 17:00
    int minDur = 30, maxDur = 120;

    Appointment* schedule = createSchedule(startTime, endTime, minDur, maxDur);

    int choice, slot;
    do {
        cout << "\n===== Appointment Scheduler =====\n";
        cout << "1. Display schedule\n";
        cout << "2. Book appointment\n";
        cout << "3. Cancel appointment\n";
        cout << "4. Sort by data swap\n";
        cout << "5. Sort by pointer manipulation\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                display(schedule);
                break;
            case 2:
                cout << "Enter slot number to book: ";
                cin >> slot;
                book(schedule, slot);
                break;
            case 3:
                cout << "Enter slot number to cancel: ";
                cin >> slot;
                cancel(schedule, slot);
                break;
            case 4:
                sortByData(schedule);
                break;
            case 5:
                schedule = sortByPointer(schedule);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
