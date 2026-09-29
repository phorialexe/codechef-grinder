#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: WECNITK - Access Code Equality
 * The problem requires checking if the input string S is exactly "WECNITK".
 * Since the problem specifies that case sensitivity matters (as per the sample 
 * "WECnitk" resulting in "Access denied"), we perform a direct string comparison.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    // The problem description implies a single input string S of length 7.
    // While the prompt mentions "Handle multiple test cases", the problem 
    // description itself does not specify a number of test cases (T).
    // We will read the string directly as per the input format.
    if (cin >> s) {
        if (s == "WECNITK") {
            cout << "Welcome to Web Club!" << "\n";
        } else {
            cout << "Access denied" << "\n";
        }
    }

    return 0;
}