#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have two guns:
 * 1. Close-range: distance <= D
 * 2. Long-range: distance > D
 * 
 * Initially, we hold the close-range gun.
 * We need to process targets in order.
 * If the current target requires a gun different from the one we are holding,
 * we must switch.
 * 
 * Let current_gun = 0 (Close-range)
 * For each target A_i:
 *   If A_i <= D: required_gun = 0
 *   Else: required_gun = 1
 *   
 *   If current_gun != required_gun:
 *     switches++
 *     current_gun = required_gun
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

void solve() {
    int N, D;
    cin >> N >> D;
    
    // current_gun: 0 for close-range, 1 for long-range
    // Initially holding close-range gun
    int current_gun = 0;
    int switches = 0;
    
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        
        int required_gun = (A <= D) ? 0 : 1;
        
        if (current_gun != required_gun) {
            switches++;
            current_gun = required_gun;
        }
    }
    
    cout << switches << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}