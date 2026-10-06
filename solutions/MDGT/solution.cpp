#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Bhoomi is at the last position (index N-1).
 * She can swap with the person in front of her.
 * She wants to reach a position 'i' such that her height H_N is strictly 
 * greater than all heights H_0, H_1, ..., H_{i-1}.
 * 
 * Since she moves one step at a time towards the front, we can simulate 
 * the process. At each step, we check if her current height is greater 
 * than all elements before her. If not, we swap her with the person 
 * immediately in front and increment the counter.
 * 
 * Constraints are small (N <= 100), so a simple simulation is O(N^2), 
 * which is well within the time limit.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> H(N);
    for (int i = 0; i < N; ++i) {
        cin >> H[i];
    }

    if (N == 1) {
        cout << 0 << "\n";
        return;
    }

    int moves = 0;
    // Bhoomi is initially at index N-1
    int current_pos = N - 1;

    while (current_pos > 0) {
        // Check if Bhoomi can see the performance at current_pos
        bool can_see = true;
        for (int i = 0; i < current_pos; ++i) {
            if (H[i] >= H[current_pos]) {
                can_see = false;
                break;
            }
        }

        if (can_see) {
            break;
        }

        // Swap with the person in front
        swap(H[current_pos], H[current_pos - 1]);
        current_pos--;
        moves++;
    }

    cout << moves << "\n";
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