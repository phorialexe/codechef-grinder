#include <iostream>
#include <string>
#include <vector>

/**
 * Problem Analysis:
 * A number is a multiple of 5 if and only if its last digit is 0 or 5.
 * Therefore, we can rearrange the digits of N to form a multiple of 5
 * if and only if the string N contains at least one '0' or at least one '5'.
 * 
 * Time Complexity: O(D) per test case, where D is the number of digits.
 * Space Complexity: O(D) to store the string of digits.
 */

using namespace std;

void solve() {
    int D;
    if (!(cin >> D)) return;
    string N;
    cin >> N;

    bool found = false;
    // Iterate through the string to check for the existence of '0' or '5'
    for (int i = 0; i < D; ++i) {
        if (N[i] == '0' || N[i] == '5') {
            found = true;
            break;
        }
    }

    if (found) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}