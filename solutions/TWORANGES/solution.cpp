#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two ranges [A, B] and [C, D]. We need to find the number of 
 * integers that belong to at least one of these ranges.
 * 
 * Since the constraints are very small (1 <= A, B, C, D <= 8), we can use a 
 * boolean array or a set to mark the integers present in the ranges and 
 * count the number of unique integers marked.
 * 
 * Time Complexity: O(T * (B-A + D-C)), which is effectively O(T) given the constraints.
 * Space Complexity: O(1) as the range of numbers is fixed and small.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        // Using a boolean array to track integers from 1 to 8
        // Since constraints are 1 <= A, B, C, D <= 8
        bool present[9] = {false};

        // Mark integers in the first range [A, B]
        for (int i = a; i <= b; ++i) {
            present[i] = true;
        }

        // Mark integers in the second range [C, D]
        for (int i = c; i <= d; ++i) {
            present[i] = true;
        }

        // Count how many integers were marked
        int count = 0;
        for (int i = 1; i <= 8; ++i) {
            if (present[i]) {
                count++;
            }
        }

        cout << count << "\n";
    }

    return 0;
}