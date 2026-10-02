#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef bakes a cake every day from date X to 24 (inclusive).
 * The number of days from X to 24 inclusive is (24 - X + 1).
 * 
 * Constraints:
 * 1 <= X <= 24
 * 
 * Example 1: X = 18
 * 24 - 18 + 1 = 7. Correct.
 * 
 * Example 2: X = 1
 * 24 - 1 + 1 = 24. Correct.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // The problem description implies a single input X, but standard competitive 
    // programming practice often involves test cases. If the problem specifies 
    // "The first and only line of input will contain a single integer X", 
    // we handle it as a single execution.
    
    int x;
    if (cin >> x) {
        int result = 24 - x + 1;
        cout << result << "\n";
    }

    return 0;
}