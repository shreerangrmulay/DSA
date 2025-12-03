#include <iostream>
using namespace std;

void bubbleSort(int marks[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (marks[j] > marks[j + 1]){
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    for (int k = 0; k < n; k++) {
        cout << marks[k] << " ";
    }
    cout << endl;
    }
}

int main(){
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    int marks[50];
    for (int i = 0; i < n; i++)
    {
        cin >> marks[i];
    }
    bubbleSort(marks,n);
    for (int i = 0; i < n; i++)
    {
        cout << marks[i] << " ";
    }

    cout << "\nRoll No Assignment\n";
    int roll = 1;
    for (int i = n - 1; i >= 0; i--) {
        cout << "Roll No. " << roll << " -> Marks: " << marks[i] << endl;
        roll++;
    }
    return 0;
}