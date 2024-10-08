#include <iostream>
using namespace std;

#define SIZE 10  // Size of the deque array

class Deque {
    int arr[SIZE];
    int front, rear;

public:
    Deque() {
        front = -1;
        rear = -1;
    }

    // Check if the deque is full
    bool isFull() {
        return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
    }

    // Check if the deque is empty
    bool isEmpty() {
        return front == -1;
    }

    // Add element to the front
    void addFront(int data) {
        if (isFull()) {
            cout << "Deque is full. Cannot add element.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (front == 0) {
            front = SIZE - 1;
        } else {
            front--;
        }
        arr[front] = data;
    }

    // Add element to the rear
    void addRear(int data) {
        if (isFull()) {
            cout << "Deque is full. Cannot add element.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else if (rear == SIZE - 1) {
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = data;
    }

    // Delete element from the front
    void deleteFront() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete element.\n";
            return;
        }
        cout << "Deleted " << arr[front] << " from front.\n";
        if (front == rear) {  // If there's only one element
            front = rear = -1;
        } else if (front == SIZE - 1) {
            front = 0;
        } else {
            front++;
        }
    }

    // Delete element from the rear
    void deleteRear() {
        if (isEmpty()) {
            cout << "Deque is empty. Cannot delete element.\n";
            return;
        }
        cout << "Deleted " << arr[rear] << " from rear.\n";
        if (front == rear) {  // If there's only one element
            front = rear = -1;
        } else if (rear == 0) {
            rear = SIZE - 1;
        } else {
            rear--;
        }
    }

    // Display the contents of the deque
    void display() {
        if (isEmpty()) {
            cout << "Deque is empty.\n";
            return;
        }
        cout << "Deque elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    Deque dq;
    dq.addRear(10);
    dq.addRear(20);
    dq.addFront(5);
    dq.display();  // Should display: 5 10 20

    dq.deleteFront();
    dq.display();  // Should display: 10 20

    dq.addRear(30);
    dq.addFront(2);
    dq.display();  // Should display: 2 10 20 30

    dq.deleteRear();
    dq.display();  // Should display: 2 10 20

    return 0;
}
