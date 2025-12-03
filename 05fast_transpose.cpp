// SPARSE MATRIX.
#include <iostream>
#include <vector>
using namespace std;
int main(){
    int mat[10][10];
    int a, b, count = 0;
    cout << "Enter rows : ";
    cin >> a;
    cout << "Enter columns : ";
    cin >> b;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {   
            cout << "Enter element " << i << " " << j << endl;
            cin >> mat[i][j];
            if (mat[i][j] != 0)
            {
                count++;
            }
        }  
    }
    int sparse[count+1][3];
    sparse[0][0] = a;
    sparse[0][1] = b;
    sparse[0][2] = count;

    int k = 1;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {   
            if (mat[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }  
        }   
    }
    cout << "This is the sparse matrix : ";
    cout << endl;
    for (int i = 0; i < count+1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << sparse[i][j] << " ";
        } 
        cout << endl;  
    }
    // THIS IS THE FAST TRANSPOSE METHOD WHICH HAS O(n) COMPLEXITY.
    int total[b] = {0};
    int index[b];
    int transpose[count+1][3];
    transpose[0][0] = b;
    transpose[0][1] = a;
    transpose[0][2] = count;
    for (int i = 1; i <= count; i++)
    {
        total[sparse[i][1]]++;
    }
    index[0] = 1;
    for (int i = 1; i < b; i++)
    {
        index[i] = index[i-1] + total[i-1];
    }
    for (int i = 1; i < count+1; i++)
    {
        int loc = index[sparse[i][1]];
        transpose[loc][0] = sparse[i][1];
        transpose[loc][1] = sparse[i][0];
        transpose[loc][2] = sparse[i][2];
        index[sparse[i][1]]++;
    }
    cout << "This is the transpose of the sparse matrix : ";
    cout << endl;
    for (int i = 0; i < count+1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << transpose[i][j] << " ";
        } 
        cout << endl;
    }
    return 0;
}