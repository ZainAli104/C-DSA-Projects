#include <iostream>
using namespace std;
struct node
{
	int data;
	node *next;
};
class test
{
	node *first;

public:
	test()
	{
		first = NULL;
	}
	void add(int x)
	{
		node *ptr, *temp;
		if (first == NULL)
		{
			first = new node;
			first->data = x;
			first->next = NULL;
		}
		else
		{
			ptr = first;
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			temp = new node;
			temp->data = x;
			temp->next = NULL;
			ptr->next = temp;
		}
	}
	void display()
	{
		node *temp = first;
		if (first == NULL)
		{
			cout << "\nEmpty";
		}
		else
		{
			while (temp->next != NULL)
			{
				cout << temp->data << endl;
				temp = temp->next;
			}
			cout << temp->data;
		}
	}
	void del(int y)
	{
		node *pre, *temp;
		temp = first;
		if (first == NULL)
		{
			cout << "Empty No Value";
		}
		else if (temp->data == y)
		{
			first = first->next;
			delete temp;
			cout << y << "Has been deleted";
		}
		else
		{
			pre = temp;
			while (temp != NULL)
			{
				if (temp->data == y)
				{
					pre->next = temp->next;
					delete temp;
					cout << y << " has been deleted." << endl;
					return;
				}
				pre = temp;
				temp = temp->next;
			}
		}
	}
};
int main()
{
	int b;
	test t1;
	t1.add(45);
	t1.add(20);
	t1.add(15);
	t1.add(82);
	t1.display();
	cout << "\nEnter Value To Delete:";
	cin >> b;
	t1.del(b);
	t1.display();
	return 0;
}
