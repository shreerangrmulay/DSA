#include <iostream>
#include <ctime>
using namespace std;
int main(){
    int mat1[10][10], mat2[10][10], mat3row[10][10], mat3col[10][10];
    int r1,c1,r2,c2;
    cout << "Enter the rows of first matrix : ";
    cin >> r1;
    cout << "Enter the column of first matrix : ";
    cin >> c1;
    cout << "Enter the rows of second matrix : ";
    cin >> r2;
    cout << "Enter the column of second matrix : ";
    cin >> c2;
    cout << "Enter the elements of first matrix : \n";
    for (int i = 0; i < r1; i++){
         for (int j = 0; j < c1; j++){
            cin >> mat1[i][j];
        }   
    }
    cout << "Enter the elements of second matrix : \n";
    for (int i = 0; i < r2; i++){
        for (int j = 0; j < c2; j++){
            cin >> mat2[i][j];
        }
    }
    cout << "Matrix one is : \n";
    for (int i = 0; i < r1; i++){ 
        for (int j = 0; j < c1; j++){
            cout << mat1[i][j] << " ";
        }  
        cout << endl;
    }
    cout << "Matrix two is : \n";
    for (int i = 0; i < r2; i++){ 
        for (int j = 0; j < c2; j++){
            cout << mat2[i][j] << " ";
        }  
        cout << endl;
    }
    clock_t start_row = clock();
    if (c1 != r2)
    {
        cout << "Matrix multiplication cannot happen : ";
        return 0;
    } else {
        for (int i = 0; i < r1; i++){
            for (int j = 0; j < c2; j++){
                mat3row[i][j] = 0;
                for (int k = 0; k < c1; k++){
                 mat3row[i][j] += mat1[i][k] * mat2[k][j];    
            }
        }
    }
    }
    clock_t end_row = clock();
    clock_t start_col = clock();
    if (c1 != r2)
    {
        cout << "Matrix multiplication cannot happen : ";
        return 0;
    } else {
        for (int j = 0; j < c2; j++){
            for (int i = 0; i < r1; i++){
                mat3col[i][j] = 0;
                for (int k = 0; k < c1; k++){
                 mat3col[i][j] += mat1[i][k] * mat2[k][j];    
            }
        }
    }
    }
    clock_t end_col = clock();
    cout << "Matrix multiplication by row major: \n";
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++)
        {
            cout << mat3row[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Matrix multiplication by column major: \n";
    for (int i = 0; i < r1; i++){
        for (int j = 0; j < c2; j++)
        {
            cout << mat3col[i][j] << " ";
        }
        cout << endl;
    }
    double time_row = double(end_row - start_row) / CLOCKS_PER_SEC;
    double time_col = double(end_col - start_col) / CLOCKS_PER_SEC;
    cout << "Row-major time: " << time_row << " seconds\n";
    cout << "Column-major time: " << time_col << " seconds\n";  
    return 0;
}