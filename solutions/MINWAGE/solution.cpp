#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: MINWAGE
 * The minimum wage is 11. We need to check if X > 11.
 * Constraints: 1 <= X <= 20.
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    // The problem description implies a single input X per run based on the format,
    // but standard competitive programming practice often involves reading until EOF 
    // or handling a specific number of test cases. Given the constraints and format:
    if (cin >> X) {
        if (X > 11) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}