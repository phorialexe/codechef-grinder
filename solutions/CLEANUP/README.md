# [Cleaning Up (CLEANUP)](https://www.codechef.com/problems/CLEANUP)

- **Difficulty Rating**: 1309
- **Solved in**: 1 attempt(s)

## Problem Summary
There are $n$ jobs to be completed, numbered from 1 to $n$. Some jobs have already been finished by the Chef. We are given the list of these completed jobs. The remaining jobs must be divided between the Chef and his assistant. The rule for distribution is that the remaining jobs are sorted in increasing order, and then they are assigned alternately: the first goes to the Chef, the second to the assistant, the third to the Chef, and so on. We need to output the jobs assigned to the Chef and the assistant, respectively.

## Intuition & Mathematical Observation
1. **Tracking Completion**: Since the job IDs are in the range $[1, n]$, we can use a boolean array (or a frequency array) of size $n+1$ to mark which jobs are already finished. This allows for $O(1)$ lookup time.
2. **Identifying Unfinished Jobs**: By iterating from $1$ to $n$, we can collect all job IDs that are not marked as finished. Because we iterate in increasing order, the resulting list of unfinished jobs is naturally sorted.
3. **Alternating Distribution**: Once we have the sorted list of unfinished jobs, we can use the index of the list to distribute them. 
   - Jobs at even indices ($0, 2, 4, \dots$) are assigned to the Chef.
   - Jobs at odd indices ($1, 3, 5, \dots$) are assigned to the assistant.
4. **Edge Cases**: If there are no jobs left for either the Chef or the assistant, the problem requires us to print `-1`.

## Complexity Analysis
- **Time Complexity**: $O(n)$, where $n$ is the total number of jobs. We iterate through the jobs once to mark them, once to collect the unfinished ones, and once to distribute them.
- **Space Complexity**: $O(n)$ to store the `finished` status array and the list of `unfinished` jobs.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: CLEANUP
 * The problem asks us to identify which jobs are remaining, then distribute them
 * between the Chef and the assistant based on their sorted order.
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
```