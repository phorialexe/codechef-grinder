#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have A choices for the first layer (1 to A) and B choices for the second layer (1 to B).
 * Total combinations without constraints = A * B.
 * Constraint: The two layers cannot have the same color.
 * The colors that are common to both sets are 1, 2, ..., min(A, B).
 * There are exactly min(A, B) such colors.
 * Therefore, we must subtract min(A, B) from the total combinations.
 * Result = (A * B) - min(A, B).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    // The problem description implies a single line of input, 
    // but standard competitive programming practice often involves test cases.
    // Given the problem format, we read A and B.
    long long A, B;
    if (cin >> A >> B) {
        long long common = min(A, B);
        long long result = (A * B) - common;
        cout << result << "\n";
    }

    return 0;
}