#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two choices for the first ingredient: a or b.
 * Chef has two choices for the second ingredient: c or d.
 * The total tastiness is the sum of the chosen first and second ingredients.
 * To maximize the sum, we pick the maximum of {a, b} and add it to the maximum of {c, d}.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;

        // The maximum tastiness is max(a, b) + max(c, d)
        long long max_first = max(a, b);
        long long max_second = max(c, d);
        
        cout << (max_first + max_second) << "\n";
    }

    return 0;
}