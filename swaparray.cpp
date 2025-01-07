#include <iostream>
using namespace std;

int printArray(int array[], int n){
    for(int i = 0; i<n; i++){
        cout << array[i] <<" ";
    }
    cout << endl;
}

int reverseArray(int array[], int n){
    int start = 0;
    int end = n-1;
    while(start<=end){
        swap(array[start], array[end]);
        start++;
        end--;
    }
}

int main(){
int a[6] = {1,2,3,4,5,6};
int b[5] = {7,8,9,10,11};

printArray(a,6);
printArray(b,5);
cout << "Array after reverse" <<endl;
reverseArray(a,6);
reverseArray(b,5);
cout << "Array after reverse" <<endl;
printArray(a,6);
printArray(b,5);
}