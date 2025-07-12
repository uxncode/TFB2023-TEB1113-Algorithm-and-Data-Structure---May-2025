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

class Queue {
private:
    static const int SIZE = 5;
    string arr[SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(string name) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        rear++;
        arr[rear] = name;
        cout << "Enqueued: " << name << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front++;
        }
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
        } else {
            cout << "Front of queue: " << arr[front] << endl;
        }
    }

    void display_queue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }

        for (int i = front; i <= rear; i++) {
            cout << arr[i];
            if (i < rear)
                cout << " -> ";
        }
        cout << endl;
    }
};

int main() {
    Queue queue;

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
