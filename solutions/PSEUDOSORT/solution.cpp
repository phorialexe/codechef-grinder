#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An array is pseudo-sorted if it is already sorted or can be sorted by 
 * swapping exactly one adjacent pair (A[i], A[i+1]).
 * 
 * Strategy:
 * 1. Check if the array is already sorted. If yes, return YES.
 * 2. If not, find the first index 'i' where A[i] > A[i+1].
 * 3. Perform the swap at this index.
 * 4. Check if the resulting array is sorted.
 * 5. If it is, return YES, otherwise return NO.
 */

bool isSorted(const vector<long long>& a) {
    int n = a.size();
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) return false;
    }
    return true;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    // Check if already sorted
    if (isSorted(a)) {
        cout << "YES" << "\n";
        return;
    }

    // Find the first inversion
    int idx = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] > a[i + 1]) {
            idx = i;
            break;
        }
    }

    // Swap the adjacent elements at the first inversion
    if (idx != -1) {
        swap(a[idx], a[idx + 1]);
    }

    // Check if sorted after the swap
    if (isSorted(a)) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}