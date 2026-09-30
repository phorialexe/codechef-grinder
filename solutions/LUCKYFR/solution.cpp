#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: LUCKYFR - Lucky Four
 * Approach:
 * For each integer provided, we can treat it as a string or process it digit by digit.
 * Since the constraint is up to 10^9, the number of digits is small (at most 10).
 * We can read the input as a string to easily iterate through each character
 * and count the occurrences of the character '4'.
 * 
 * Time Complexity: O(T * D), where T is the number of test cases and D is the number of digits.
 * Space Complexity: O(D) to store the string representation of the number.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        string s;
        cin >> s;

        int count = 0;
        for (char c : s) {
            if (c == '4') {
                count++;
            }
        }
        cout << count << "\n";
    }

    return 0;
}