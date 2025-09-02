#include<iostream>
using namespace std;

int main(){
    // Input the number of days and the stock prices for those days
    int n;
    cout << "Enter the number of days: ";
    cin >> n;
    if(n <= 0) {
        cout << "Invalid number of days." << endl;
        return 0;
    }
    cout << "Enter the stock prices for each day: ";
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    int profit = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] > arr[i - 1]){
            profit += arr[i] - arr[i - 1];
        }   
        if(arr[i] < arr[i - 1]) {
            // If the price is lower than the previous day, we do not buy
            continue;
        }
        if(i==n-1 && arr[i] > arr[i - 1]) {
            // If it's the last day and the price is higher than the previous day, we sell
            profit += arr[i] - arr[i - 1];
        }
        
    }
    // Output the maximum profit
    
    cout <<"Maximum profit:"<< profit << endl;
    return 0;
}
