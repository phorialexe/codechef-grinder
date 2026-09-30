#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * An element is dominant if its frequency is strictly greater than the frequency 
 * of any other element in the array.
 * 
 * Strategy:
 * 1. Count the frequency of each element in the array.
 * 2. Store these frequencies in a collection (e.g., a vector or map).
 * 3. Sort the frequencies in descending order.
 * 4. If the highest frequency is strictly greater than the second-highest frequency,
 *    then a dominant element exists.
 * 5. Special case: If there is only one unique element, it is dominant by default.
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> freq;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[a[i]]++;
    }

    // Extract frequencies into a vector
    vector<int> counts;
    for (auto const& [val, count] : freq) {
        counts.push_back(count);
    }

    // If there's only one unique element, it's dominant
    if (counts.size() == 1) {
        cout << "YES" << "\n";
        return;
    }

    // Sort frequencies in descending order
    sort(counts.rbegin(), counts.rend());

    // Check if the largest frequency is strictly greater than the second largest
    if (counts[0] > counts[1]) {
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