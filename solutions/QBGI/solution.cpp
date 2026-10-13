#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to iterate through the string S and keep track of the number of boys (B)
 * and girls (G) who have entered the bar.
 * Let 'boys' be the count of 'B' and 'girls' be the count of 'G'.
 * The condition for closing the gate is: boys > 2 * girls.
 * We need to count how many people enter before this condition is met.
 * 
 * Logic:
 * 1. Initialize boys = 0, girls = 0.
 * 2. Iterate through the string character by character.
 * 3. For each character, update the respective count.
 * 4. Check if (boys > 2 * girls).
 * 5. If true, the current person is the last one allowed to enter (or the gate closes
 *    immediately after them), so we stop and return the count of people processed so far.
 * 6. If the loop finishes without the condition being met, all N people entered.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int boys = 0;
    int girls = 0;
    int allowed = 0;

    for (int i = 0; i < N; ++i) {
        if (S[i] == 'B') {
            boys++;
        } else {
            girls++;
        }
        
        allowed++;
        
        // Check if the condition is met
        if (boys > 2 * girls) {
            break;
        }
    }

    cout << allowed << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}