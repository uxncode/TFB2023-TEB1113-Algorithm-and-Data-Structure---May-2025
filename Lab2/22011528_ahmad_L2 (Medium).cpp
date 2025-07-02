/* 
*************************
Id : 22011528
Name : Ahmad Waffy Rez'Daniel Bin Ahmad Rizal
Lab : 2
(Medium) - Rotate a Matrix by 180 degree
problem: https://geeksforgeeks.org/rotate-matrix-180-degree/

*************************
*/

#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "Enter matrix size: "; cin >> n;

    int mat[100][100];

    cout << "Enter matrix elements (" << n * n << " values):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    cout << "Matrix after 180 degree rotation:\n";
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
