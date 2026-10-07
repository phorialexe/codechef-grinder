#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A permutation P is ambiguous if P[i] = inverse_P[i] for all i.
 * The inverse permutation is defined such that if P[i] = j, then inverse_P[j] = i.
 * Therefore, the condition for ambiguity is:
 * P[P[i]] = i (using 1-based indexing).
 * 
 * Given the constraints (n up to 100,000), an O(n) approach per test case is optimal.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // The problem states the input ends with a zero.
    while (cin >> n && n != 0) {
        // Using a vector to store the permutation. 
        // Size n+1 to accommodate 1-based indexing.
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }

        bool ambiguous = true;
        // Check the condition: P[P[i]] == i
        // If P[i] = j, then the inverse permutation has i at position j.
        // For the permutation to be ambiguous, the value at position j in the 
        // original permutation must be i.
        for (int i = 1; i <= n; ++i) {
            if (p[p[i]] != i) {
                ambiguous = false;
                break;
            }
        }

        if (ambiguous) {
            cout << "ambiguous" << "\n";
        } else {
            cout << "not ambiguous" << "\n";
        }
    }

    return 0;
}