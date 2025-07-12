/* 
*************************
Id : 22011528
Name : Ahmad Waffy Rez'Daniel Bin Ahmad Rizal
Lab : 6
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

class Queue {
private:
    Node* front;
    Node* rear;
    int max_size;
    int current_size;

public:
    Queue(int size) {
        front = nullptr;
        rear = nullptr;
        max_size = size;
        current_size = 0;
    }

    bool isFull() {
        return current_size == max_size;
    }

    bool isEmpty() {
        return current_size == 0;
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        Node* new_node = new Node(name);
        if (isEmpty()) {
            front = rear = new_node;
        } else {
            rear->next = new_node;
            rear = new_node;
        }

        current_size++;
        cout << "Enqueued: " << name << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        Node* temp = front;
        front = front->next;
        cout << "Dequeued: " << temp->name << endl;
        delete temp;
        current_size--;

        if (front == nullptr) {
            rear = nullptr;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
        } else {
            cout << "Front of queue: " << front->name << endl;
        }
    }

    void display_queue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
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
    Queue queue(5);

    queue.enqueue("Ali");
    queue.enqueue("Ahmed");
    queue.enqueue("Alee");
    queue.enqueue("Alice");

    cout << "Current queue: ";
    queue.display_queue();

    queue.peek();
    queue.dequeue();

    cout << "After dequeue: ";
    queue.display_queue();

    return 0;
}
