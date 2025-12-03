// #include <iostream>
// using namespace std;

// int partition(int marks[], int low, int high) {
//     int pivot = marks[low];   // pivot = first element
//     int i = low + 1;
//     int j = high;

//     while (true) {
//         while (i <= high && marks[i] <= pivot) i++;
//         while (j >= low && marks[j] > pivot) j--;

//         if (i < j) {
//             swap(marks[i], marks[j]);
//         } else {
//             break;
//         }
//     }
//     swap(marks[low], marks[j]);   // place pivot correctly
//     return j;
// }

// void QuickSort(int marks[], int low, int high) {
//     if (low < high) {
//         int p = partition(marks, low, high);
//         QuickSort(marks, low, p - 1);
//         QuickSort(marks, p + 1, high);
//     }
// }
// int main(){
//     int n, marks[50];
//     cout << "Enter number of students : ";
//     cin >> n;
//     for (int i = 0; i < n; i++){
//         cin >> marks[i];
//     }
//     QuickSort(marks,0,n-1);
//     for (int i = 0; i < n; i++)
//     {
//         cout << marks[i] << " ";
//     }
    
//     return 0;
// }
#include <iostream>
using namespace std;

void printArray(const int a[], int n) {
    for (int i = 0; i < n; i++) cout << a[i] << (i+1<n ? " " : "");
    cout << "\n";
}

int partition(int a[], int low, int high) {
    int pivot = a[low];
    int i = low + 1, j = high;

    while (true) {
        while (i <= high && a[i] <= pivot) i++;
        while (j >= low && a[j] >  pivot) j--;
        if (i < j) swap(a[i], a[j]);
        else break;
    }
    swap(a[low], a[j]);              
    return j;
}

void quickSortPasses(int a[], int low, int high, int n, int &pass) {
    if (low < high) {
        int p = partition(a, low, high);
        cout << "Pass " << (++pass) << " (pivot=" << a[p]
             << " at index " << p << "): ";
        printArray(a, n);
        quickSortPasses(a, low,  p - 1, n, pass);
        quickSortPasses(a, p + 1, high, n, pass);
    }
}

struct MinMax { 
    int mn; 
    int mx; 
};

MinMax minMaxDC(const int a[], int low, int high) {
    if (low == high) {                
        return {a[low], a[low]};
    }
    if (high == low + 1) {            
        if (a[low] < a[high]) 
            return {a[low], a[high]};
        else                   
            return {a[high], a[low]};
    }
    int mid = (low + high) / 2;
    MinMax L = minMaxDC(a, low, mid);
    MinMax R = minMaxDC(a, mid + 1, high);
    MinMax res;
    if (L.mn < R.mn)
        res.mn = L.mn;
    else
        res.mn = R.mn;

    if (L.mx > R.mx)
        res.mx = L.mx;
    else
        res.mx = R.mx;
    return res;
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    int marks[200];
    cout << "Enter " << n << " marks:\n";
    for (int i = 0; i < n; i++) 
        cin >> marks[i];

    cout << "\nInitial: ";
    printArray(marks, n);

   
    int pass = 0;
    quickSortPasses(marks, 0, n - 1, n, pass);

    cout << "\nSorted (ascending): ";
    printArray(marks, n);

    MinMax mm = minMaxDC(marks, 0, n - 1);
    cout << "Minimum mark: " << mm.mn << "\n";
    cout << "Maximum mark: " << mm.mx << "\n";
    return 0;
}
