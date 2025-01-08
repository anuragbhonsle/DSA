#include <iostream>
using namespace std;

int getPivot(int arr[], int size) {
    int start = 0;
    int end = size - 1;
    while (start < end) {
        int mid = start + (end - start) / 2;

        // Check if mid is the pivot
        if (mid < end && arr[mid] > arr[mid + 1]) {
            return mid + 1;
        }
        if (mid > start && arr[mid] < arr[mid - 1]) {
            return mid;
        }

        // Update start or end
        if (arr[mid] >= arr[start]) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return start; // Pivot found
}

int main() {
    int arr[5] = {3, 4, 5, 1, 2};
    int pivot = getPivot(arr, 5);
    cout << "Pivot index: " << pivot << endl; // Output: Pivot index: 3
    return 0;
}

/*

{3,5,7,9,0,1,2}; 0+6/2 = 3; 9>0; start = 3;
{0,1,2} 4+6/2 = 5; 1<2
{0,1} 4+5/2= 4; 0<1

*/

