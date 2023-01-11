#include <iostream>
using namespace std;

class Stack {
    int arr[3];
    int top;

    public:
    Stack() {
        top = -1;
    }

    void push(int x) {
        if (top == 2) {
            cout << "Stack is overflow" << endl;
        }
        else {
            top++;
            arr[top] = x;
            cout << arr[top] << " + " << top << endl;
        }
    }

    void pop() {
        if (top == -1) {
            cout << "No element in stack to pop";
        }
        else {
            cout << arr[top--] << endl;
        }
    }

    bool empty() {
        return top==-1;
    }
};

int main() {
    Stack obj1;
    obj1.push(10);
    obj1.push(20);
    obj1.push(30);

    obj1.pop();
    cout << obj1.empty();

    return 0;
}