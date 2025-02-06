#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    stack<int> s;

    s.push(-3);
    s.push(1);
    s.push(-7);
    s.push(5);
    s.push(-9);
    s.push(7);
    s.push(-4);

    vector<int> temp;

    // Move elements from stack to vector
    while (!s.empty())
    {
        temp.push_back(s.top());
        s.pop();
    }

    // Print elements before sorting
    cout << "Original elements (from stack): ";
    for (int i = 0; i < temp.size(); i++)
    {
        cout << temp[i] << " ";  // Added space for readability
    }
    cout << endl;

    // Sort the vector
    sort(temp.begin(), temp.end());
    reverse(temp.begin(), temp.end());
    // Push sorted elements back into the stack
    for (int j = 0; j < temp.size(); j++)
    {
        s.push(temp[j]);
    }

    // Print the sorted stack
    cout << "Sorted stack elements (top to bottom): ";
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
