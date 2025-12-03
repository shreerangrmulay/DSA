#include <iostream>
using namespace std;

struct Student
{
    string name;
    int rollno;
    string year;
    string div;
};
Student students[100];
int main(){
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter name, roll no, year, div : ";
        cin >> students[i].name >> students[i].rollno >> students[i].year >> students[i].div;
    }
    for (int i = 0; i < 3; i++)
    {
        if ((students[i].year == "S.Y.") && (students[i].div == "X") && (students[i].name == "XYZ") && (students[i].rollno == 17))
        {
            cout << "Student Record Found on " << i << " index\n";
            break;
        } else {
            cout << "Not Found on the index " << i << "\n";
        }
    }
    return 0;
}