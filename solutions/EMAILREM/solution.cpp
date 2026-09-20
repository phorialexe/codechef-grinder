#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N total participants and U participants who opted out.
 * The number of participants to send emails to is simply N - U.
 * 
 * Constraints:
 * 1 <= U < N <= 10^5
 * Since N and U fit within a standard 32-bit integer, 'int' is sufficient,
 * but 'long long' is used for safety and best practices in competitive programming.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case per run based on the input format,
    // but standard practice is to handle input as specified.
    // Given the problem description: "The first and only line of input will contain..."
    // We read N and U once.
    
    long long N, U;
    if (cin >> N >> U) {
        long long result = N - U;
        cout << result << "\n";
    }

    return 0;
}