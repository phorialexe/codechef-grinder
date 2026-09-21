#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Team A scored R runs.
 * Team B has played O overs and scored C runs.
 * Remaining overs = 20 - O.
 * In each over, there are 6 balls, and each ball can score a maximum of 6 runs.
 * Maximum runs per over = 6 * 6 = 36.
 * Maximum runs possible in remaining overs = (20 - O) * 36.
 * Maximum total score for Team B = C + (20 - O) * 36.
 * Team B wins if (Maximum total score) > R.
 * 
 * Complexity:
 * Time: O(1) per test case.
 * Space: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single line of input for one test case.
    // However, standard competitive programming practice often involves multiple test cases.
    // Based on the problem description, we read R, O, and C.
    long long R, O, C;
    if (!(cin >> R >> O >> C)) return 0;

    long long remaining_overs = 20 - O;
    long long max_additional_runs = remaining_overs * 36;
    long long max_total_score = C + max_additional_runs;

    if (max_total_score > R) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }

    return 0;
}