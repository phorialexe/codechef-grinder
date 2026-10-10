#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a range [L, R]. We need to determine if there exists at least one even integer in this range.
 * 
 * Logic:
 * - If L == R, the range contains only one number. If that number is even, output Yes, else No.
 * - If L < R, the range contains at least two numbers. Any two consecutive integers 
 *   must contain at least one even number (since one is odd and the other is even).
 *   Therefore, if L < R, the answer is always Yes.
 * 
 * Constraints: 1 <= L <= R <= 10.
 * The logic holds for all integers.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, R;
    if (!(cin >> L >> R)) return 0;

    // If the range contains more than one number, it must contain an even number.
    // If the range contains only one number, check if it is even.
    if (L < R) {
        cout << "Yes" << "\n";
    } else {
        // L == R, check if the single number is even
        if (L % 2 == 0) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}