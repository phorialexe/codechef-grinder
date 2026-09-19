#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * There are N people and X tiles.
 * In each round, every person picks 1 tile.
 * This means in one round, N tiles are consumed.
 * For the game to be valid:
 * 1. All tiles must be used at the end. This implies X must be divisible by N (X % N == 0).
 * 2. All players must have a tile in each round. This implies X must be at least N (X >= N).
 * 
 * Combining these, the condition is (X % N == 0) AND (X >= N).
 * Since X >= N and X % N == 0 implies X/N is a positive integer, 
 * the condition simplifies to X % N == 0.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, x;
        cin >> n >> x;

        // The game is valid if X is a multiple of N.
        // Since X >= N is guaranteed if X % N == 0 and X, N >= 1,
        // we only need to check the divisibility.
        if (x % n == 0) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}