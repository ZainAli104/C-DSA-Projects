#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class linkedList {
    node* first;
    node* ptr;
    node* temp;
    public:
    linkedList() {
        first  = NULL;
    }
    void addNode(int val) {
        if (first == NULL) {
            first = new node;
            first->data = val;
            first->next = NULL;
        }
        else {
            ptr = first;
            while (ptr->next != NULL) {
                ptr = ptr->next;
            }
            temp = new node;
            temp->data = val;
            temp->next = NULL;
            ptr->next = temp;
        }
    }
    void display() {
        if (first == NULL) {
            cout << "No Data" << endl;
        }
        else {
            ptr = first;
            while (ptr != NULL) {
                cout << ptr->data << " -> ";
                ptr = ptr->next;
            }
            cout << "NULL" << endl;
        }
    }
    void Delete(int val) {
        if (first == NULL) {
            cout << "There is no data!";
            return;
        }
        if (first->next == NULL) {
            delete first;
            cout << "First Node has been deleted!";
            return;
        }
        node* pre = new node;
        pre = first;
        while (pre != NULL) {
            if (pre->data == val) {
                pre->next = first->next;
                delete first;
                cout << val << " has been Deleted!" << endl;
                return;
            }
            pre = first;
            first = first->next;
        }
    }
};

int main() {
    linkedList obj1;
    obj1.addNode(1);
    obj1.addNode(2);
    obj1.addNode(3);
    obj1.display();
    obj1.Delete(2);
    obj1.display();

    return 0;
}
