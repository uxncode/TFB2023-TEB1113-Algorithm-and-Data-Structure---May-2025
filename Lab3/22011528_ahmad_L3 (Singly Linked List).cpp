/* 
*************************
Id : 22011528
Name : Ahmad Waffy Rez'Daniel Bin Ahmad Rizal
Lab : 3
*************************
*/

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string name) {
        this->name = name;
        this->next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_node(string name) {
        Node* new_node = new Node(name);

        if (head == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }

        cout << "Added node: " << name << endl;
    }

    void display_list() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->name << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void delete_by_value(string name) {
        Node* current = head;
        Node* previous = nullptr;

        while (current != nullptr) {
            if (current->name == name) {
                if (current == head) {
                    head = head->next;
                    if (current == tail) tail = nullptr;
                } else {
                    previous->next = current->next;
                    if (current == tail) tail = previous;
                }
                delete current;
                cout << "Deleted node: " << name << endl;
                return;
            }
            previous = current;
            current = current->next;
        }

        cout << "Node with value '" << name << "' not found." << endl;
    }
};

int main() {
    LinkedList list;

    list.add_node("Ali");
    list.add_node("Ahmed");
    list.add_node("Alee");

    cout << "Current list: ";
    list.display_list();

    list.delete_by_value("Ahmed");

    cout << "After deletion: ";
    list.display_list();

    return 0;
}
