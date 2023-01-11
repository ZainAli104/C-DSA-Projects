#include <iostream>
using namespace std;
struct node
{
    int data;
    node *link;
    node()
    {
        data = 0;
        link = NULL;
    }
};
class circular
{
    node *first, *last;

public:
    circular()
    {
        first = NULL;
        last = NULL;
    }
    void add_s(int a)
    {
        if (first == NULL)
        {
            first = new node;
            first->data = a;
            first->link = NULL;
            last = first;
            return;
        }
        else
        {
            node *ptr = new node;
            ptr->data = a;
            ptr->link = first;
            first = ptr;
            last->link = first;
        }
    }
    void add_e(int b)
    {
        if (first == NULL)
        {
            first = new node;
            first->data = b;
            first->link = NULL;
            last = first;
            return;
        }
        else
        {
            node *ptr = new node;
            last->link = ptr;
            ptr->data = b;
            ptr->link = first;
            last = ptr;
        }
    }
    void remove_s()
    {
        if (first == NULL)
        {
            cout << "No Value!";
            return;
        }
        if (first->link == first)
        {
            delete first;
            last = NULL;
            return;
        }
        else
        {
            node *ptr = first;
            first = first->link;
            last->link = first;
            delete ptr;
        }
    }
    void remove_e()
    {
        if (first == NULL)
        {
            cout << "no value to Display!";
            return;
        }
        if (first->link == first)
        {
            delete first;
            last = NULL;
            return;
        }
        else
        {
            node *ptr = first;
            while (ptr->link != last)
            {
                ptr = ptr->link;
            }
            ptr->link = first;
            delete last;
            last = ptr;
        }
    }
    void show()
    {
        if (first == NULL)
        {
            cout << "List Is Empty!";
        }
        else
        {
            node *temp = first;
            cout << "Values are:\n";
            while (temp->link != first)
            {
                cout << temp->data << endl;
                temp = temp->link;
            }

            cout << temp->data << endl;
        }
    }
};
int main()
{
    circular s1;
    s1.add_s(10);
    s1.add_e(20);
    s1.add_e(30);
    s1.add_e(40);
    s1.add_e(50);
    s1.add_e(60);
    s1.show();
    s1.remove_s();
    s1.remove_e();
    s1.show();
    return 0;
}
