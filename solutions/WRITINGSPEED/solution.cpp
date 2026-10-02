#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Rahul has 5 pages to write.
 * Time limit = 60 minutes.
 * Time per page = X minutes.
 * Total time taken = 5 * X minutes.
 * Condition: 5 * X <= 60
 * Simplifying: X <= 12
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single input X per run, 
    // but standard competitive programming practice often involves 
    // handling a single test case unless specified otherwise.
    // Given the constraints and format, we read X and evaluate.
    
    int X;
    if (!(cin >> X)) return 0;

    // Rahul needs to complete 5 pages.
    // Total time = 5 * X.
    // Constraint is 60 minutes.
    if (5 * X <= 60) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}