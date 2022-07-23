#include <iostream>

/**
 * Static implementation of Queue Data Structure
 */

const int MAX_SIZE = 100;

class Queue {
private:
    size_t front, rear;
    bool empty;
    int queue[MAX_SIZE];
public:
    Queue() {
        front = rear = 0;
        empty = true;
    }

    void enqueue(int n) {
        if (front == rear && !empty) {
            throw std::overflow_error("Опашката е пълна!");
        }
        queue[rear++] = n;
        if (rear >= MAX_SIZE) {
            rear = 0;
        }
        empty = false;
    }

    int& dequeue() {
        if (empty) {
            throw std::runtime_error("Опашката е празна");
        }
        int elem = queue[front++];
        if (front >= MAX_SIZE) {
            front = 0;
        }
        if (front == rear) {
            empty = true;
        }
        return elem;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
