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