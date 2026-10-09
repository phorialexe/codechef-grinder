#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Calorie Intake
 * Chef's limit: X
 * Already consumed: Y * Z
 * Remaining: X - (Y * Z)
 * If (Y * Z) > X, output -1.
 * 
 * Constraints: 1 <= X, Y, Z <= 100.
 * Since the values are small, standard int is sufficient, 
 * but long long is used for safety as per instructions.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the format,
    // but standard competitive programming practice handles potential multiple inputs.
    // Given the problem description "The first and only line of input contains 3 integers",
    // we process exactly one set of inputs.
    
    long long X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    long long consumed = Y * Z;

    if (consumed > X) {
        cout << -1 << "\n";
    } else {
        cout << (X - consumed) << "\n";
    }

    return 0;
}