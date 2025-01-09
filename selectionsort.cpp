#include <iostream>
using namespace std;

int main(){
    int arr[7]= {2,5,7,8,1,12,17};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i<n; i++){
        int minIndex = i;
        for(int j = i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }swap(arr[minIndex], arr[i]);
    }
    //Print the sorted array
    for(int i = 0; i<n; i++){
        cout << arr[i] << " ";
    }
}
/*
Selection sort ko kab use karna hai? 
-> Jab bhi array ka size chota hai.
   Tab tum ye algo use kar sakte ho to sort the array.

   Time Complexity is O(n^2)
   Space Complexity is O(1)
*/