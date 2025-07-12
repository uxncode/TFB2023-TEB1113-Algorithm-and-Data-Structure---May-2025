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
    Node* prev;
    Node* next;

    Node(string name) {
        this->name = name;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void add_node(string name) {
        Node* new_node = new Node(name);

        if (head == nullptr) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
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
            cout << current->name << " <-> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void delete_by_value(string name) {
        Node* current = head;

        while (current != nullptr) {
            if (current->name == name) {
                if (current == head) {
                    head = head->next;
                    if (head) head->prev = nullptr;
                    if (current == tail) tail = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Deleted node: " << name << endl;
                return;
            }
            current = current->next;
        }

        cout << "Node with value '" << name << "' not found." << endl;
    }
};

int main() {
    DoublyLinkedList list;

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

