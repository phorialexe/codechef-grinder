#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each round of Surya Namaskar consists of 12 yoga poses.
 * Given N total poses, the number of completed rounds is the integer division of N by 12.
 * 
 * Constraints:
 * 1 <= N <= 100
 * Time Complexity: O(1) per test case
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single input N, 
    // but standard competitive programming practice often involves 
    // handling a single test case unless specified otherwise.
    // Based on the prompt "Handle multiple test cases", we implement the loop.
    
    int n;
    if (cin >> n) {
        // Calculate completed rounds using integer division
        int rounds = n / 12;
        cout << rounds << "\n";
    }

    return 0;
}