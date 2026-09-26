#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N coins. In round k (1 <= k <= N), we flip coins 1 to k.
 * Let's observe the state of coin i after N rounds.
 * Coin i is flipped in round k if and only if k >= i.
 * So, coin i is flipped for k = i, i+1, ..., N.
 * The total number of flips for coin i is (N - i + 1).
 * 
 * If (N - i + 1) is even, the coin returns to its initial state.
 * If (N - i + 1) is odd, the coin changes its state.
 * 
 * Total coins = N.
 * Number of coins that flip an odd number of times:
 * N - i + 1 is odd <=> N - i is even <=> N and i have the same parity.
 * 
 * Let's count how many i in [1, N] have the same parity as N:
 * - If N is even:
 *   - Even i: 2, 4, ..., N (N/2 coins)
 *   - Odd i: 1, 3, ..., N-1 (N/2 coins)
 * - If N is odd:
 *   - Even i: 2, 4, ..., N-1 ((N-1)/2 coins)
 *   - Odd i: 1, 3, ..., N ((N+1)/2 coins)
 * 
 * General rule:
 * If N is even, N/2 coins flip an odd number of times, N/2 flip an even number.
 * If N is odd, (N+1)/2 coins flip an odd number of times, (N-1)/2 flip an even number.
 * 
 * If I == Q:
 * We want the count of coins that end up in the initial state.
 * These are the coins that flipped an even number of times.
 * If I != Q:
 * We want the count of coins that changed state.
 * These are the coins that flipped an odd number of times.
 */

void solve() {
    long long I, N, Q;
    cin >> I >> N >> Q;

    long long odd_flips = N / 2;
    if (N % 2 != 0) {
        odd_flips = (N + 1) / 2;
    }
    long long even_flips = N - odd_flips;

    if (I == Q) {
        // We want the count of coins that didn't change state (even flips)
        cout << even_flips << "\n";
    } else {
        // We want the count of coins that changed state (odd flips)
        cout << odd_flips << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        int G;
        cin >> G;
        while (G--) {
            solve();
        }
    }
    return 0;
}