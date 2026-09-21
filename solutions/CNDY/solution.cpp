#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/**
 * Problem Analysis:
 * We are given 2N integers. We need to split them into two arrays of size N
 * such that each array contains distinct elements.
 * This is possible if and only if no element appears more than twice in the 
 * original array. If an element appears 3 or more times, it's impossible to 
 * distribute them into two sets without having a duplicate in at least one.
 */

void solve() {
    int n;
    cin >> n;
    int total_elements = 2 * n;
    map<int, int> counts;
    bool possible = true;

    for (int i = 0; i < total_elements; ++i) {
        int a;
        cin >> a;
        counts[a]++;
        if (counts[a] > 2) {
            possible = false;
        }
    }

    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }

    return 0;
}