#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A subarray has a non-zero product if and only if it contains no zeros.
 * The problem reduces to finding the length of the longest contiguous segment 
 * of the array that does not contain the number 0.
 * 
 * Algorithm:
 * 1. Iterate through the array.
 * 2. Maintain a counter for the current length of a non-zero segment.
 * 3. If the current element is non-zero, increment the counter.
 * 4. If the current element is zero, update the global maximum length and reset the counter to 0.
 * 5. After the loop, perform one final update to the global maximum to account for a segment 
 *    ending at the last element.
 * 
 * Complexity:
 * Time: O(N) - Single pass through the array.
 * Space: O(1) - Only a few integer variables used.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    int max_len = 0;
    int current_len = 0;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;

        if (a != 0) {
            current_len++;
        } else {
            if (current_len > max_len) {
                max_len = current_len;
            }
            current_len = 0;
        }
    }

    // Final check in case the longest segment ends at the last element
    if (current_len > max_len) {
        max_len = current_len;
    }

    cout << max_len << "\n";

    return 0;
}