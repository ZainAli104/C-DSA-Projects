#include <iostream>
using namespace std;

#define n 20

class queue {
    int* arr;
    int front, back;

    public:
    queue() {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    // enqueue
    void push(int val) {
        if (back == n-1) {
            cout << "Queue is Overflow" << endl;
            return;
        }
        back++;
        arr[back] = val;

        if (front == -1) {
            front++;
        }
    }

    // dequeue
    void pop() {
        if (front == -1 || front>back) {
            cout << "Queue is Empty" << endl;
            return;
        }
        cout << arr[front++] << " Delete is successfull!" << endl;
    }

    int peek() {
        if (front == -1 || front>back) {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool Empty() {
        if (front == -1 || front>back) {
            return true;
        }
        return false;
    }
};

int main() {
    queue obj1;

    cout << obj1.Empty() <<  endl;

    obj1.push(10);
    obj1.push(20);
    obj1.push(30);

    cout << obj1.peek() << endl;
    obj1.pop();
    cout << obj1.peek() << endl;

    cout << obj1.Empty() <<  endl;

    return 0;
}
