#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Alice starts as the server.
 * - If the current server wins the point, their score increases by 1, and they remain the server.
 * - If the receiver wins the point, their score does not increase, but they become the server.
 * 
 * We can maintain a variable `server` to track who is currently serving (0 for Alice, 1 for Bob).
 * Alice's score `alice_score` and Bob's score `bob_score` are updated based on the rules.
 */

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    int alice_score = 0;
    int bob_score = 0;
    
    // server: 0 represents Alice, 1 represents Bob
    int server = 0; 

    for (int i = 0; i < N; ++i) {
        char winner = S[i];
        
        if (server == 0) { // Alice is server
            if (winner == 'A') {
                // Alice wins as server
                alice_score++;
                // Alice remains server
            } else {
                // Bob wins as receiver
                // Bob becomes server
                server = 1;
            }
        } else { // Bob is server
            if (winner == 'B') {
                // Bob wins as server
                bob_score++;
                // Bob remains server
            } else {
                // Alice wins as receiver
                // Alice becomes server
                server = 0;
            }
        }
    }

    cout << alice_score << " " << bob_score << "\n";
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