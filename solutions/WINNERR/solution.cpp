#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The time penalty for a participant is defined as the maximum of the time 
 * taken to solve problem A and problem B (since they must have solved both).
 * Let P_penalty = max(P_A, P_B)
 * Let Q_penalty = max(Q_A, Q_B)
 * 
 * We compare P_penalty and Q_penalty:
 * - If P_penalty < Q_penalty, P wins.
 * - If Q_penalty < P_penalty, Q wins.
 * - If P_penalty == Q_penalty, it is a TIE.
 * 
 * Constraints: 1 <= P_A, P_B, Q_A, Q_B <= 100.
 * Time complexity: O(1) per test case.
 * Space complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int pa, pb, qa, qb;
        cin >> pa >> pb >> qa >> qb;
        
        // Calculate the time penalty for each participant
        int p_penalty = max(pa, pb);
        int q_penalty = max(qa, qb);
        
        // Compare penalties and output the result
        if (p_penalty < q_penalty) {
            cout << "P" << "\n";
        } else if (q_penalty < p_penalty) {
            cout << "Q" << "\n";
        } else {
            cout << "TIE" << "\n";
        }
    }
    
    return 0;
}