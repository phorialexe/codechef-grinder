#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: CLEANUP
 * The problem asks us to identify which jobs are remaining, then distribute them
 * between the Chef and the assistant based on their sorted order.
 * 
 * Approach:
 * 1. Use a boolean array or a set to mark jobs that are already completed.
 * 2. Iterate from 1 to n to collect all unfinished jobs in a list.
 * 3. Distribute the unfinished jobs:
 *    - Chef takes indices at positions 0, 2, 4, ... (even indices in the list)
 *    - Assistant takes indices at positions 1, 3, 5, ... (odd indices in the list)
 * 4. Print the results, handling the case where a list is empty by printing -1.
 */

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    vector<bool> finished(n + 1, false);
    for (int i = 0; i < m; ++i) {
        int job;
        cin >> job;
        finished[job] = true;
    }

    vector<int> unfinished;
    for (int i = 1; i <= n; ++i) {
        if (!finished[i]) {
            unfinished.push_back(i);
        }
    }

    vector<int> chef, assistant;
    for (int i = 0; i < (int)unfinished.size(); ++i) {
        if (i % 2 == 0) {
            chef.push_back(unfinished[i]);
        } else {
            assistant.push_back(unfinished[i]);
        }
    }

    // Print Chef's jobs
    if (chef.empty()) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < (int)chef.size(); ++i) {
            cout << chef[i] << (i == (int)chef.size() - 1 ? "" : " ");
        }
        cout << "\n";
    }

    // Print Assistant's jobs
    if (assistant.empty()) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < (int)assistant.size(); ++i) {
            cout << assistant[i] << (i == (int)assistant.size() - 1 ? "" : " ");
        }
        cout << "\n";
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