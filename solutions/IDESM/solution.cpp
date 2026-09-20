#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: The Ides of March
 * The problem asks us to determine if a given day N in March is the 15th.
 * Constraints: 1 <= N <= 15.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem statement implies a single integer N per input.
    // Although the prompt mentions "Handle multiple test cases", 
    // the problem description only specifies a single integer N.
    // We will read N and check if it equals 15.
    
    int N;
    if (cin >> N) {
        if (N == 15) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}