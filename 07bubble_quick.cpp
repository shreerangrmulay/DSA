#include <iostream>
#include <vector>
using namespace std;

struct student
{
    string name;
    int roll_no;
    int totalMarks;
};

int quickSwapCount = 0;
int bubbleSwapCount = 0;

int partition(vector<student> &arr,int f,int l){
    int i = f, j = l + 1;
    int pivot = arr[f].roll_no;
    do
    {
        do
        {   i++;    
        } while (i <= l && arr[i].roll_no < pivot);
        do{
            j--;
        } while (j >= f && arr[j].roll_no > pivot);
        if (i < j)
        {
            swap(arr[i],arr[j]);
            quickSwapCount++;
        }
    } while (i < j);
    swap(arr[f],arr[j]);
    quickSwapCount++;
    return j;
}

void Quicksort(vector<student> &arr,int f,int l){
    if (f < l)
    {
        int j = partition(arr,f,l);
        Quicksort(arr,f,j-1);
        Quicksort(arr,j+1,l);
    }
    return ;
}

void BubbleSort(vector<student> &arr) {
    int n = arr.size();
    bubbleSwapCount = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].roll_no > arr[j + 1].roll_no) {
                swap(arr[j], arr[j + 1]);
                bubbleSwapCount++;
            }
        }
    }
}

int main(){
    vector<student> arr, arrCopy;
    int n;
    cout << "Enter the number of the students : ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {   
        student s;
        cout << "Enter the name, roll no, marks respectively" << endl;
        getline(cin,s.name);
        cin >> s.roll_no >> s.totalMarks;
        cin.ignore();
        arr.push_back(s);
    }
    arrCopy = arr;
    Quicksort(arr, 0, n-1);

    cout << "\nStudents sorted by roll numbers (ascending) by Quicksort:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << " " << arr[i].roll_no << " " << arr[i].totalMarks << endl;        
    }
    cout << "Number of Swaps (quicksort) : " << quickSwapCount << endl;

    BubbleSort(arrCopy);

    cout << "\nStudents sorted by roll numbers (ascending) Bubblesort:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i].name << " " << arr[i].roll_no << " " << arr[i].totalMarks << endl;        
    }
    cout << "Number of Swaps (bubblesort) : " << bubbleSwapCount << endl;
    return 0;
}