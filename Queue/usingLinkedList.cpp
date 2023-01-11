#include <iostream>
using namespace std;

class node {
    public:
    int data;
    node* next;

    node(int x) {
        data = x;
        next = NULL;
    }
};

class queue {
    node* front;
    node* back;

    public:
    queue() {
        front = NULL;
        back = NULL;
    }

    void push(int x) {
        node* n = new node(x);

        if (front == NULL) {
            front = n;
            back = n;
            return;
        }

        back->next = n;
        back = n;
    }

    void pop() {
        if (front == NULL) {
            cout << "Queue is under flow" << endl;
            return;
        }

        node* temp = front;
        front = front->next;
        
        delete temp;
    }

    int peek() {
        if (front == NULL) {
            cout << "No element in Queue" << endl;
            return -1;
        }

        return front->data;
    }

    bool isEmpty() {
        return front == NULL;
    }
};

int main() {
    queue obj1;

    cout << obj1.isEmpty() << endl;

    obj1.push(10);
    obj1.push(20);
    obj1.push(30);

    cout << obj1.peek() << endl;
    obj1.pop();
    cout << obj1.peek() << endl;

    cout << obj1.isEmpty() << endl;

    return 0;
}