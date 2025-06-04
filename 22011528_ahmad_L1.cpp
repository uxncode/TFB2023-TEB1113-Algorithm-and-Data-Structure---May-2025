/* 
*************************
Id : 22011528
Name : Ahmad Waffy Rez'Daniel Bin Ahmad Rizal
Lab : 1
*************************
*/

#include <iostream>
#include <string>
using namespace std;

struct Student {
    string name;
    int id;
    string phone;
    string email;
}; 

int main() {
    Student stud[5];

    for (int i = 0; i < 5; i++) {
        cout << "Enter details for student " << i + 1 << ":" << endl;
        
        cout << "Name: ";
        getline(cin >> ws, stud[i].name);

        cout << "ID: ";
        cin >> stud[i].id;

        cout << "Phone: ";
        cin >> stud[i].phone;

        cout << "Email: ";
        cin >> stud[i].email;

        cout << endl;
    }
    
    cout << endl << "Student details:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i + 1 << ":" << endl;
        cout << "Name: " << stud[i].name << endl;
        cout << "ID: " << stud[i].id << endl;
        cout << "Phone: " << stud[i].phone << endl;
        cout << "Email: " << stud[i].email << endl << endl;
    }

    return 0;
}
