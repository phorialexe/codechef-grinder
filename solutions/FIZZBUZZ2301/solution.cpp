#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Fan Poll (FIZZBUZZ2301)
 * Logic: Dhoni wins if A > B and A > C.
 * Since the problem guarantees no two players received the same number of votes,
 * we simply check if A is strictly greater than both B and C.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, C;
    // The problem description implies a single test case per input based on the format,
    // but we structure it to handle input as specified.
    if (cin >> A >> B >> C) {
        if (A > B && A > C) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}