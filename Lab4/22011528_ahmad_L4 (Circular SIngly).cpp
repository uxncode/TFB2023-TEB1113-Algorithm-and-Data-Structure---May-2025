/* 
*************************
Id : 22011528
Name : Ahmad Waffy Rez'Daniel Bin Ahmad Rizal
Lab : 4
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
            tail->next = head;
        } else {
            tail->next = new_node;
            tail = new_node;
            tail->next = head;
        }

        cout << "Added node: " << name << endl;
    }

    void display_list() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        do {
            cout << current->name << " -> ";
            current = current->next;
        } while (current != head);
        cout << head->name << endl;
    }

    void delete_by_value(string name) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;
        Node* previous = tail;

        do {
            if (current->name == name) {
                if (current == head) {
                    if (head == tail) {
                        delete head;
                        head = tail = nullptr;
                    } else {
                        head = head->next;
                        tail->next = head;
                        delete current;
                    }
                } else {
                    previous->next = current->next;
                    if (current == tail) {
                        tail = previous;
                    }
                    delete current;
                }
                cout << "Deleted node: " << name << endl;
                return;
            }
            previous = current;
            current = current->next;
        } while (current != head);

        cout << "Node with value '" << name << "' not found." << endl;
    }
};

int main() {
    LinkedList list;

    list.add_node("Ali");
    list.add_node("Ahmed");
    list.add_node("Alee");
    list.add_node("Hamza");

    cout << "Current list: ";
    list.display_list();

    list.delete_by_value("Ahmed");

    cout << "After deletion: ";
    list.display_list();

    return 0;
}

