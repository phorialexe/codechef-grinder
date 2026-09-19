#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Dominant Army
 * Logic:
 * An army is dominant if its size is strictly greater than the sum of the other two.
 * We check three conditions:
 * 1. NA > NB + NC
 * 2. NB > NA + NC
 * 3. NC > NA + NB
 * If any of these are true, output YES, else NO.
 */

void solve() {
    long long NA, NB, NC;
    if (!(cin >> NA >> NB >> NC)) return;

    if (NA > (NB + NC) || NB > (NA + NC) || NC > (NA + NB)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
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