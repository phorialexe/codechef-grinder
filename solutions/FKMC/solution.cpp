#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice wants to maximize the number of '1's in the string.
 * She can choose one contiguous substring of '0's and flip them all to '1's.
 * 
 * Strategy:
 * 1. Count the total number of '1's already present in the string.
 * 2. Identify all contiguous blocks of '0's.
 * 3. For each block of '0's, its length represents the number of additional '1's 
 *    Alice can gain by applying the operation on that specific block.
 * 4. To maximize the total '1's, we should choose the longest contiguous block of '0's.
 * 5. If there are no '0's, the answer is just the total count of '1's.
 * 6. The result is (Total '1's) + (Length of the longest contiguous block of '0's).
 */

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int total_ones = 0;
    int max_zeros = 0;
    int current_zeros = 0;

    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            total_ones++;
            // Reset zero counter when we hit a '1'
            current_zeros = 0;
        } else {
            current_zeros++;
            // Update the maximum block of zeros found so far
            if (current_zeros > max_zeros) {
                max_zeros = current_zeros;
            }
        }
    }

    // The result is the initial count of ones plus the longest sequence of zeros
    cout << total_ones + max_zeros << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}