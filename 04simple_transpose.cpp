#include <iostream>
using namespace std;

int main()
{
    int mat[10][10];
    int a = 0;
    int b = 0;
    int cnt = 0;
    cout << "Enter number of rows: ";
    cin >> a;
    cout << endl << "Enter number of colums: ";
    cin >> b;
    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cout << endl << "Enter element " << i << "," << j <<" :";
            cin >> mat[i][j];
            if(mat[i][j] != 0)
            {
                cnt++;
            } 
        }   
    }
    int saprse[cnt+1][3];
    saprse[0][0] = a;
    saprse[0][1] = b;
    saprse[0][2] = cnt;
    int k = 1;
    for (int i = 0; i < a; i++){
        for (int j = 0; j < b; j++){
            if(mat[i][j] != 0)
            {
                saprse[k][0] = i;
                saprse[k][1] = j;
                saprse[k][2] = mat[i][j];
                k++;
            }
        }
        
    }
    cout << endl << "sparse matrix is: " << endl;
    for (int i = 0; i < cnt + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << saprse[i][j] << " ";
        }
        cout << endl; 
    }

    int transpose[cnt+1][3];
    transpose[0][0] = saprse[0][1];
    transpose[0][1] = saprse[0][0];
    transpose[0][2] = saprse[0][2];

    int l = 1;
    for (int i = 0; i < b; i++)
    {
        for (int j = 1; j < cnt + 1; j++)
        {
            if( saprse[j][1] == i)
            {
                transpose[l][0] = saprse[j][1];
                transpose[l][1] = saprse[j][0];
                transpose[l][2] = saprse[j][2];
                l++;
            }
        }
    }
    cout << endl << "Transpose of sparse matrix is: " << endl;
    for (int i = 0; i < cnt + 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}