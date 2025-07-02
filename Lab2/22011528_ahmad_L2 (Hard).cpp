/* 
*************************
Id : 22011528
Name : Ahmad Waffy Rez'Daniel Bin Ahmad Rizal
Lab : 2
(Hard) - A Boolean Matrix Question
problem: https://geeksforgeeks.org/a-boolean-matrix-question/

*************************
*/

#include <iostream>
using namespace std;

int main() {
    int rows, cols;

    cout << "Enter number of rows and columns: "; cin >> rows >> cols;

    int mat[100][100];

    cout << "Enter matrix elements (0 or 1):\n";
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++){
            cin >> mat[i][j];
        }
        
    bool rowMarker[100] = {false};
    bool colMarker[100] = {false};

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (mat[i][j] == 1) {
                rowMarker[i] = true;
                colMarker[j] = true;
            }
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (rowMarker[i] || colMarker[j]) {
                mat[i][j] = 1;
            }
        }
    }

    cout << "Modified matrix:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
