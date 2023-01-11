#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int r) {
    
}

void mergeSort(int arr[], int l, int r) {

    if (l < r) {
        int mid = (l+r);
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);

        merge(arr, l, mid, r);
    }
}

int main() {


    return 0;
}