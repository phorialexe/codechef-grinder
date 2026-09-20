#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The menu prices are powers of 2: 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048.
 * This is equivalent to representing a number in binary, but with a constraint:
 * we only have powers of 2 up to 2^11 (2048).
 * 
 * To minimize the number of items, we should use the largest possible menu prices first (Greedy approach).
 * Since we can use the 2048 menu multiple times, for any price p:
 * 1. Use as many 2048s as possible: count += p / 2048; p %= 2048;
 * 2. For the remainder, represent it as a sum of powers of 2 (which is exactly the number of set bits in the binary representation of the remainder).
 * 
 * Time Complexity: O(T * log(p))
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int p;
        cin >> p;

        int count = 0;

        // Use the largest menu price (2048) as much as possible
        count += p / 2048;
        p %= 2048;

        // For the remainder, count the number of set bits (1s in binary representation)
        // This corresponds to the minimum number of items using powers of 2 from 1 to 1024
        while (p > 0) {
            if (p & 1) {
                count++;
            }
            p >>= 1;
        }

        cout << count << "\n";
    }

    return 0;
}