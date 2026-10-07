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
 * 
 * Complexity:
 * - Time: O(N) per test case, O(Sum of N) total.
 * - Space: O(N) to store the presence status of IDs.
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