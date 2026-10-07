# [Card Swipe (CARDSWIPE)](https://www.codechef.com/problems/CARDSWIPE)

- **Difficulty Rating**: 1172
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to track the number of people inside an office based on a sequence of card swipes. Each swipe by a specific ID toggles the person's status: if they are outside, they enter; if they are inside, they leave. We need to determine the **maximum number of people** present in the office at any single point in time during the sequence of $N$ swipes.

## Intuition & Mathematical Observation
- The state of each person (inside or outside) can be represented using a boolean flag. Since IDs are given up to $N$, we can use a boolean array or a `vector<bool>` of size $N+1$ to track their presence.
- We maintain a counter `current_people` to track the number of people currently inside.
- For every swipe:
    - If the person is currently inside (`is_inside[id] == true`), they are leaving. We set `is_inside[id] = false` and decrement `current_people`.
    - If the person is currently outside (`is_inside[id] == false`), they are entering. We set `is_inside[id] = true` and increment `current_people`.
- After each swipe, we compare `current_people` with a variable `max_people` to keep track of the peak occupancy.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of swipes. We iterate through the list of swipes exactly once, performing constant-time operations for each.
- **Space Complexity**: $O(N)$ to store the `is_inside` status for each unique ID.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to track the number of people currently inside the office.
 * A swipe by an ID toggles their status:
 * - If they are not in the office, they enter (count increases).
 * - If they are in the office, they leave (count decreases).
 * We need to maintain the maximum value this count reaches during the process.
 * 
 * Data Structures:
 * - A boolean array or a hash set to track the current presence of each ID.
 * - Since IDs are up to N (where N <= 2*10^5), a vector<bool> or a simple 
 *   array is efficient for O(1) lookups.
 */

void solve() {
    int n;
    if (!(cin >> n)) return;
    
    // Using a vector to track if a person is currently inside.
    // IDs are 1-indexed up to N.
    vector<bool> is_inside(n + 1, false);
    
    int current_people = 0;
    int max_people = 0;
    
    for (int i = 0; i < n; ++i) {
        int id;
        cin >> id;
        
        if (is_inside[id]) {
            // Person is leaving
            is_inside[id] = false;
            current_people--;
        } else {
            // Person is entering
            is_inside[id] = true;
            current_people++;
        }
        
        // Update the maximum observed count
        if (current_people > max_people) {
            max_people = current_people;
        }
    }
    
    cout << max_people << "\n";
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
```