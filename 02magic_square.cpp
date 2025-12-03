#include <iostream>
#include <vector>
using namespace std;

void generateOddMagicSquare(vector<vector<int>>& square, int n) {
    int num = 1, i = 0, j = n / 2;
    while (num <= n * n) {
        square[i][j] = num++;
        int newi = (i - 1 + n) % n;
        int newj = (j + 1) % n;
        if (square[newi][newj])
            i = (i + 1) % n;
        else {
            i = newi;
            j = newj;
        }
    }
}

void generateDoublyEvenMagicSquare(vector<vector<int>>& square, int n) {
    int num = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            square[i][j] = num++;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (((i % 4 == j % 4) || ((i + j) % 4 == 3)))
                square[i][j] = n * n + 1 - square[i][j];
}


bool verifyMagicSquare(const vector<vector<int>>& square, int n) {
    int magicSum = n * (n * n + 1) / 2;
    for (int i = 0; i < n; i++) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += square[i][j];
            colSum += square[j][i];
        }
        if (rowSum != magicSum || colSum != magicSum)
            return false;
    }
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < n; i++) {
        diag1 += square[i][i];
        diag2 += square[i][n - i - 1];
    }
    if (diag1 != magicSum || diag2 != magicSum)
        return false;
    return true;
}

int main() {
    int n;
    cout << "Enter order of magic square (n): ";
    cin >> n;
    if (n < 3) {
        cout << "Order must be >= 3\n";
        return 0;
    }
    vector<vector<int>> square(n, vector<int>(n, 0));
    if (n % 2 == 1) {
        generateOddMagicSquare(square, n);
    } else if (n % 4 == 0) {
        generateDoublyEvenMagicSquare(square, n);
    } else {
        cout << "Magic square construction for singly even order (n = 4k+2) is not implemented.\n";
        return 0;
    }
    cout << "\nMagic Square of order " << n << ":\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << square[i][j] << "\t";
        cout << endl;
    }
    if (verifyMagicSquare(square, n))
        cout << "This is a valid magic square.\n";
    else
        cout << "This is NOT a valid magic square.\n";
}