/* 
*************************
Id : 22011528
Name : Ahmad Waffy Rez'Daniel Bin Ahmad Rizal
Lab : 5
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

class Stack {
private:
    Node* top;
    int max_size;
    int current_size;

public:
    Stack(int size) {
        top = nullptr;
        max_size = size;
        current_size = 0;
    }

    bool isFull() {
        return current_size == max_size;
    }

    void push(string name) {
        if (isFull()) {
            cout << "Stack is full. Cannot push." << endl;
            return;
        }

        Node* new_node = new Node(name);
        new_node->next = top;
        top = new_node;
        current_size++;

        cout << "Pushed: " << name << endl;
    }

    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        Node* temp = top;
        top = top->next;
        cout << "Popped: " << temp->name << endl;
        delete temp;
        current_size--;
    }

    void peek() {
        if (top == nullptr) {
            cout << "Stack is empty. Nothing to peek." << endl;
        } else {
            cout << "Top of stack: " << top->name << endl;
        }
    }

    void display_stack() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }

        Node* current = top;
        while (current != nullptr) {
            cout << current->name;
            if (current->next != nullptr)
                cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack(5);

    stack.push("Ali");
    stack.push("Ahmed");
    stack.push("Alee");
    stack.push("Alice");

    cout << "Current stack: ";
    stack.display_stack();

    stack.peek();
    stack.pop();

    cout << "After popping: ";
    stack.display_stack();

    return 0;
}
