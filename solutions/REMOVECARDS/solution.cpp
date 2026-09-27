#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N cards with values A_i. We want to keep only cards that have the same value.
 * To minimize the number of moves (removals), we should maximize the number of cards 
 * we keep.
 * 
 * If we decide to keep all cards that have the value 'X', we will keep 'count(X)' cards.
 * The number of moves required would be N - count(X).
 * To minimize this, we need to maximize count(X).
 * 
 * Algorithm:
 * 1. Count the frequency of each card value present in the input.
 * 2. Find the maximum frequency among all values.
 * 3. The answer is N - max_frequency.
 * 
 * Constraints:
 * N <= 100, A_i <= 10.
 * This approach is O(N) per test case, which is well within the time limit.
 */

void solve() {
    int N;
    cin >> N;
    
    // Since A_i is small (1 to 10), we can use a frequency array of size 11.
    vector<int> freq(11, 0);
    for (int i = 0; i < N; ++i) {
        int val;
        cin >> val;
        freq[val]++;
    }
    
    int max_freq = 0;
    for (int i = 1; i <= 10; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
        }
    }
    
    // Minimum moves = Total cards - cards of the most frequent value
    cout << (N - max_freq) << "\n";
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