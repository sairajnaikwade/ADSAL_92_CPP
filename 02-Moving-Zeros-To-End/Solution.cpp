/*
Assignment 2:- Implement the problem of moving all zeroes to the end of array.
Statement: Given an array of random numbers, Push all the zeroes of a
given array to the end of the array.
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(int arr[], int st, int mid, int end) {
    vector<int> temp;
    int i = st, j = mid + 1;

    // Merge two sorted halves
    while (i <= mid && j <= end) {
        if (arr[i] >= arr[j]) {
            
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    // left
    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }
    // right
    while (j <= end) {
        temp.push_back(arr[j]);
        j++;
    }

    for (int k = 0; k < (int)temp.size(); k++) {
        arr[st + k] = temp[k];
    }
}

void mergeSort(int arr[], int st, int end) {
    if (st < end) {
        int mid = st + (end - st) / 2;
        mergeSort(arr, st, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, st, mid, end);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int* arr = new int[n];  // dynamically allocate array

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    delete[] arr;  // free allocated memory
    return 0;
}

/*Enter 5 elements:
1 
0
2
0
3
Sorted array: 3 2 1 0 0 */
