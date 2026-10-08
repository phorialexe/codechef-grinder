#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef wants to buy 2 ice creams, each costing X.
 * Total cost = 2 * X.
 * Chef has Y dollars.
 * Condition: Chef can buy if Y >= 2 * X.
 * 
 * Constraints: 1 <= X, Y <= 100.
 * Since the values are small, standard 'int' is sufficient, 
 * but 'long long' is used for safety against potential overflow in similar problems.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description does not explicitly state multiple test cases,
    // but the instructions mention "Handle multiple test cases (e.g. int t; cin >> t; while(t--))".
    // Based on the problem format, we read X and Y.
    long long X, Y;
    if (cin >> X >> Y) {
        if (Y >= 2 * X) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}