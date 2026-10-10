#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef is at position X. He needs to reach 50.
 * He rolls two dice, each with values {Y, Y+1, Y+2, Y+3, Y+4, Y+5}.
 * Let the two dice values be d1 and d2.
 * The move distance is S = d1 + d2.
 * Chef wins if X + S = 50, which means S = 50 - X.
 * 
 * The minimum possible sum S_min = Y + Y = 2Y.
 * The maximum possible sum S_max = (Y+5) + (Y+5) = 2Y + 10.
 * 
 * Since each die can take any value from {Y, ..., Y+5}, the sum S can take 
 * any integer value from 2Y to 2Y + 10.
 * 
 * Therefore, Chef can reach 50 if and only if:
 * 2Y <= (50 - X) <= 2Y + 10.
 */

void solve() {
    int X, Y;
    if (!(cin >> X >> Y)) return;

    int target = 50 - X;
    int min_sum = 2 * Y;
    int max_sum = 2 * Y + 10;

    if (target >= min_sum && target <= max_sum) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}