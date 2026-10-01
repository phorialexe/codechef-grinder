#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Sushil is at the N-th position (index N-1 in 0-indexed array).
 * His wealth is A[N-1].
 * He can bully the person directly in front of him if that person's wealth 
 * is <= (Sushil's wealth / 2).
 * Since he only bullies the person directly in front of him, we check 
 * from the person at index N-2 down to 0.
 * As long as the condition holds, he moves forward (position decreases).
 * Once he encounters someone he cannot bully, he stops moving forward.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    int sushilWealth = A[N - 1];
    int currentPos = N; // 1-based position

    // Start checking from the person immediately in front of Sushil
    for (int i = N - 2; i >= 0; --i) {
        // Condition: wealth <= Sushil's wealth / 2
        // Using integer division as per problem statement (A_i <= X/2)
        if (A[i] <= (sushilWealth / 2)) {
            currentPos--;
        } else {
            // Cannot bully this person, so Sushil stops here
            break;
        }
    }

    cout << currentPos << "\n";
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