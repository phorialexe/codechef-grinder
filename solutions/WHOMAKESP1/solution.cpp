#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Tyro makes the problem if he is convinced, which happens if the number of times 
 * Dom asks (B) is greater than or equal to Tyro's patience level (A).
 * If B < A, Tyro is not convinced within the allowed attempts, so Dom makes it.
 * 
 * Logic:
 * If A <= B: Tyro makes the problem.
 * If A > B: Dom makes the problem.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B;
    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice handles input robustly.
    if (cin >> A >> B) {
        if (A <= B) {
            cout << "Tyro" << "\n";
        } else {
            cout << "Dom" << "\n";
        }
    }

    return 0;
}