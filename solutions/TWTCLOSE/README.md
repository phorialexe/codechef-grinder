# [Closing the Tweets (TWTCLOSE)](https://www.codechef.com/problems/TWTCLOSE)

- **Difficulty Rating**: 1291
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ tweets, initially all closed. We need to process $K$ operations. There are two types of operations:
1. `CLICK X`: If tweet $X$ is open, it closes; if it is closed, it opens.
2. `CLOSEALL`: All currently open tweets are closed.

After each operation, we must output the total number of currently open tweets.

## Intuition & Mathematical Observation
- Since $N$ and $K$ are relatively small (up to 1000), we can maintain the state of each tweet using an array or a vector of size $N+1$.
- We use a boolean or integer array where `0` represents "closed" and `1` represents "open".
- To avoid iterating through the entire array to count open tweets after every operation, we maintain a running counter `open_count`.
    - When `CLICK X` toggles a tweet from `0` to `1`, we increment `open_count`.
    - When `CLICK X` toggles a tweet from `1` to `0`, we decrement `open_count`.
    - When `CLOSEALL` is called, we reset the entire array to `0` and reset `open_count` to `0`.
- This approach ensures that each operation is handled in $O(1)$ time (or $O(N)$ for `CLOSEALL`), making the total runtime efficient.

## Complexity Analysis
- **Time Complexity**: $O(K + K \cdot N)$ in the worst case (if every operation is `CLOSEALL`), but effectively $O(K)$ for `CLICK` operations. Given the constraints, this is well within the time limit.
- **Space Complexity**: $O(N)$ to store the state of the $N$ tweets.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Closing the Tweets
 * Approach:
 * We maintain an array (or vector) of size N+1 to track the state of each tweet.
 * 0 represents closed, 1 represents open.
 * We also maintain a counter 'open_count' to keep track of the number of open tweets.
 * 
 * For 'CLICK X':
 * If state[X] is 0, we set it to 1 and increment open_count.
 * If state[X] is 1, we set it to 0 and decrement open_count.
 * 
 * For 'CLOSEALL':
 * We reset the state array to all 0s and set open_count to 0.
 * 
 * Time Complexity: O(K) for processing clicks, where K is the number of clicks.
 * Space Complexity: O(N) to store the state of N tweets.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    if (!(cin >> N >> K)) return 0;

    // state[i] stores the status of tweet i (1-indexed)
    vector<int> state(N + 1, 0);
    int open_count = 0;

    for (int i = 0; i < K; ++i) {
        string command;
        cin >> command;

        if (command == "CLICK") {
            int x;
            cin >> x;
            if (state[x] == 0) {
                state[x] = 1;
                open_count++;
            } else {
                state[x] = 0;
                open_count--;
            }
        } else if (command == "CLOSEALL") {
            // Reset all tweets to closed
            fill(state.begin(), state.end(), 0);
            open_count = 0;
        }

        cout << open_count << "\n";
    }

    return 0;
}
```