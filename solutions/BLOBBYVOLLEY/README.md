# [Blobby Volley Scores (BLOBBYVOLLEY)](https://www.codechef.com/problems/BLOBBYVOLLEY)

- **Difficulty Rating**: 962
- **Solved in**: 1 attempt(s)

## Problem Summary
In a game of Blobby Volley, Alice and Bob play a series of points. The rules for scoring and serving are as follows:
1. Alice starts as the server.
2. If the current server wins the point, they earn a point and remain the server.
3. If the receiver wins the point, they do not earn a point, but they become the new server for the next round.
Given the sequence of point winners, determine the final scores of Alice and Bob.

## Intuition & Mathematical Observation
The problem can be solved by simulating the game turn-by-turn. We need to track three variables:
*   `alice_score`: Alice's current score.
*   `bob_score`: Bob's current score.
*   `server`: A state variable (e.g., 0 for Alice, 1 for Bob) to track who is currently serving.

**Logic flow:**
- If the current server wins the point (`winner == 'A'` when `server == 0` OR `winner == 'B'` when `server == 1`), increment the server's score. The server remains the same.
- If the current server loses the point, the server changes to the other player. No score is incremented in this case.

By iterating through the string $S$ once, we can determine the outcome of every point based on the current server state.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string $S$. We iterate through the string exactly once per test case.
- **Space Complexity**: $O(N)$ to store the input string $S$, or $O(1)$ if we process the string character by character.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Alice starts as the server.
 * - If the current server wins the point, their score increases by 1, and they remain the server.
 * - If the receiver wins the point, their score does not increase, but they become the server.
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
            } else {
                // Bob wins as receiver, becomes new server
                server = 1;
            }
        } else { // Bob is server
            if (winner == 'B') {
                // Bob wins as server
                bob_score++;
            } else {
                // Alice wins as receiver, becomes new server
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
```