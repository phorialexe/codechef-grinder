#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three players with initial scores A, B, and C.
 * We have M matches to play. In each match, one player gains +1 point.
 * We want to know if it's possible to reach a state where at least two players have the same score.
 * 
 * Let the final scores be A', B', and C'.
 * The total points added is M, so (A' + B' + C') = (A + B + C) + M.
 * 
 * Since M is very small (up to 10), we can observe the condition for two players to have the same score.
 * Two players have the same score if the difference between their initial scores can be 
 * bridged or neutralized by the M matches.
 * 
 * Specifically, if we want A' = B', then |A - B| must be reachable by distributing the M points.
 * Actually, it's simpler: if we pick two players, say Alice and Bob, we can give all M points to Cameron.
 * Then their scores remain A and B. If A == B, they are already equal.
 * If we give some points to Alice or Bob, we can change the difference.
 * 
 * The condition for two players (say A and B) to be equal is:
 * |A - B| <= M.
 * Why? 
 * If A < B, we can give (B - A) points to Alice. This uses (B - A) matches.
 * If (B - A) <= M, we have used some matches and the remaining matches (M - (B - A)) 
 * can be distributed such that the equality holds (e.g., give the rest to Cameron).
 * If (M - (B - A)) is odd, we can give one point to Alice and one to Bob to keep them equal,
 * or give two points to Cameron.
 * 
 * Thus, the condition is simply:
 * Is |A - B| <= M OR |B - C| <= M OR |A - C| <= M?
 */

void solve() {
    int A, B, C, M;
    cin >> A >> B >> C >> M;

    if (abs(A - B) <= M || abs(B - C) <= M || abs(A - C) <= M) {
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