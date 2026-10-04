#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cards numbered 1 to N.
 * Chef throws card X.
 * We need to find how many cards Y (where Y is in {1, ..., N} and Y != X)
 * satisfy the condition that (X + Y) is even.
 * 
 * (X + Y) is even if and only if X and Y have the same parity (both even or both odd).
 * 
 * Let:
 * - count_odd be the total number of odd cards in {1, ..., N}.
 * - count_even be the total number of even cards in {1, ..., N}.
 * 
 * If X is odd:
 * Chefina needs to pick an odd card Y such that Y != X.
 * The number of such cards is (count_odd - 1).
 * 
 * If X is even:
 * Chefina needs to pick an even card Y such that Y != X.
 * The number of such cards is (count_even - 1).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // Total odd numbers in range [1, N]
        long long count_odd = (n + 1) / 2;
        // Total even numbers in range [1, N]
        long long count_even = n / 2;

        if (x % 2 != 0) {
            // X is odd, we need to pick another odd card
            cout << (count_odd - 1) << "\n";
        } else {
            // X is even, we need to pick another even card
            cout << (count_even - 1) << "\n";
        }
    }

    return 0;
}