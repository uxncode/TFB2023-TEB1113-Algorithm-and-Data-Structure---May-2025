/* 
*************************
Id : 22011528
Name : Ahmad Waffy Rez'Daniel Bin Ahmad Rizal
Lab : 2
(Easy) - Efficiently compute sums of diagonals of a matrix
problem: https://geeksforgeeks.org/efficiently-compute-sums-of-diagonals-of-a-matrix/
*************************
*/

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter matrix size: "; cin >> n;

    int matrix[100][100]; 

    cout << "Enter matrix elements (" << n * n << " values):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    int principalSum = 0, secondarySum = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                principalSum += matrix[i][j];

            if (i == n - j - 1)
                secondarySum += matrix[i][j];
        }
    }

    cout << "Principal Diagonal: " << principalSum << endl;
    cout << "Secondary Diagonal: " << secondarySum << endl;

    return 0;
}
