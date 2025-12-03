#include <iostream>
using namespace std;

int stringLength(char str1[]){
    int len = 0;
    for (int i = 0; str1[i] != '\0'; i++)
    {
        len++;
    }
    return len;
}
void stringCopy(char str3[], char str1[]){
    int i = 0;
    for (; str1[i] != '\0'; i++)
    {
        str3[i] = str1[i];
    }
    str3[i] = '\0';
}
void stringReverse(char str1[]){
    int i = 0;
    int j = stringLength(str1)-1;
    while(i <= j){
        swap(str1[i],str1[j]);
        i++;
        j--;
    }
}
void stringConcat(char str1[], char str2[]){
    int i = stringLength(str1);
    int j = 0;
    for (; str2[j] != '\0'; j++)
    {   
        str1[i] = str2[j];
        i++;
    }
    str1[i] = '\0';
}
int main(){
    char str1[100], str2[100], str3[100];
    cout << "Enter the first string :- ";
    cin >> str1;
    cout << "Enter the second string :- ";
    cin >> str2;

    cout << "Length of first string: " << stringLength(str1) << endl;

    stringCopy(str3,str1);
    cout << "Copy of first string: " << str3 << endl;

    stringReverse(str1);
    cout << "Reversed first string: " << str1 << endl;

    stringConcat(str1,str2);
    cout << "Concatenation of first and second string: " << str1 << endl;

    return 0;
}