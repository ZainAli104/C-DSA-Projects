#include <iostream>
using namespace std;
int main() 
{
	int k;
	cout<<"Enter the size of array:";
	cin>>k;
	int data[k];
	for(int j=0;j<k;j++)
	{
		cout<<"Enter "<<j+1<<" value:";
		cin>>data[j];
	}
	int size = k;
	//sort start
	for (int s= 0; s < size - 1; s++)
	{
		int min= s;
		for (int z = s+1; z < size; z++)
		{
			if (data[z] < data[min])			// Select the minimum element in each loop. // To sort in descending order, change > to < in this line.
			min= z;
		}
     //swap
	 int *a=&data[min],*b=&data[s];
	 
	 int temp = *a;
	 *a = *b;
	 *b = temp;
	}
	//display
	cout << "Sorted array in Acsending Order:\n";
	for (int i = 0; i < k; i++)
	{
		cout << data[i] << " ";
	}
	cout << endl;
	
	return 0;
}