#include <iostream>
#include <vector>
using namespace std;

int main()
{   int n;
cout <<"Enter the size of vector " << endl;
    cin >> n;
    vector<int> a(n); // Declaring and initializing the vector

    cout << "Enter the elements in vector " << endl;                // Getting the size of the vector
    for(int m = 0; m<n; m++){
        cin >> a[m];
    }
    for (int i = 0; i < n; i++)
    {                                // Iterating through the vector
        cout << a[i] << " "; // Printing each element
    }
    for (int j = 0; j < n; j++)
    {
        int count = 0;
        for (int k = j + 1; k < n; k++)
        {
            if (a[j] == a[k])
            {
                count++;
            }
        }
        if (count == 1)
        {
            cout << "There is an element that is present two times" << endl;
        }
        if (count == 2)
        {
            cout << "There is an element that is present three times" << endl;
        }
    }
    return 0; 
}
