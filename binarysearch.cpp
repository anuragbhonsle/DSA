#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int key){

    int start = 0;
    int end = size-1;

    int mid = (start + end)/2;

    while(start <= end){
        if(arr[mid] == key){
            return mid;
        }
        if(arr[mid] > key){
            end = mid - 1;
        }
        if(arr[mid] < key){
            start = mid + 1;
        }
        mid = (start + end)/2;
    }
    return -1;
}

int main(){

    int even[6] = {2,4,6,8,10,18};
    int odd[5] = {3,6,7,9,14};

    int evenIndex = binarySearch(even, 6, 10);
    if(evenIndex == -1){
        cout << "The key is not present in the array " << endl;
    }else{
        cout << "The key is present at index " << evenIndex << endl;
    }

    int oddIndex = binarySearch(odd, 5, 7);
    if(oddIndex == -1){
        cout << "The key is not present in the array " << endl;
    }else{
        cout << "The key is present at index " << oddIndex << endl;
    }
}