#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxVowels(string s, int k) {
        string vowels = "aeiou";
        int n = s.length();
        int count = 0;
        int curr = 0;

        for (int i = 0; i < k; i++) {
            if (vowels.find(s[i]) != string::npos) {
                curr++;
            }
        }
        count = curr;

        for (int i = k; i < n; i++) {
            if (vowels.find(s[i]) != string::npos) {
                curr++;
            }
            if (vowels.find(s[i - k]) != string::npos) {
                curr--;
            }
            count = max(count, curr);
        }

        return count;
    }
};

int main() {
    Solution solution;
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;

    cout << "Enter the value of k: ";
    cin >> k;

    int result = solution.maxVowels(s, k);
    cout << "The maximum number of vowels in any substring of length " << k << " is: " << result << endl;

    return 0;
}
