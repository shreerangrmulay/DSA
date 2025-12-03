#include <iostream>
#include <vector>
using namespace std;

struct Employee
{
    int height;
    int weight;
    double avg;
};

void SelectionSort(Employee arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j].avg < arr[minIndex].avg) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void merge(Employee arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Employee L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i].avg <= R[j].avg) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void MergeSort(Employee arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main(){
    int n;
    cout << "Enter number of employees : ";
    cin >> n;
    Employee arr1[100], arr2[100];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the height and the weight of the employee " << i+1 << " :";
        cin >> arr1[i].height >> arr1[i].weight;
        arr1[i].avg = (arr1[i].height + arr1[i].weight) / 2.0;
        arr2[i] = arr1[i];
    }

    SelectionSort(arr1, n);
    cout << "\nEmployees sorted by average (Selection Sort):\n";
    for (int i = 0; i < n; i++) {
        cout << arr1[i].height << " " << arr1[i].weight 
             << " Avg: " << arr1[i].avg << endl;
    }

    MergeSort(arr2, 0, n - 1);
    cout << "\nEmployees sorted by average (Merge Sort):\n";
    for (int i = 0; i < n; i++) {
        cout << arr2[i].height << " " << arr2[i].weight 
             << " Avg: " << arr2[i].avg << endl;
    }

    cout << "\n--- Time Complexity Analysis ---\n";
    cout << "Selection Sort: O(n^2)\n";
    cout << "Merge Sort: O(n log n)\n";
    cout << "=> Merge Sort will take less time for larger lists.\n";

    return 0;
}