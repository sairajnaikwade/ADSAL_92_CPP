#include<iostream>
using namespace std;

int main() {
    int size, array[20], zerocount = 0;
    cout << "enter array size: ";
    cin >> size;
    
    cout << "enter array elements:\n";
    for(int index = 0; index < size; index++) {
        cout << "enter element " << index << ": ";
        cin >> array[index];
    }

    int start = 0, end = size - 1, mid;
    int firstzeroindex = -1;

    while(start <= end) {
        mid = (start + end) / 2;

        if(array[mid] == 1) {
            start = mid + 1;
        }
        else {
            if(mid == 0 || array[mid - 1] == 1) {
                firstzeroindex = mid;
                break;
            }
            else {
                end = mid - 1;
            }
        }
    }

    if(firstzeroindex != -1) {
        for(int i = firstzeroindex; i < size; i++) {
            zerocount++;
        }
    }

    cout << "the total 0s in this array are: " << zerocount;
    return 0;
}
