#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N candies with colors A_1, ..., A_N.
 * We need to find the color that appears most frequently.
 * If there is a tie in frequency, we choose the smallest color value.
 * 
 * Constraints:
 * T <= 100, N <= 100, A_i <= N.
 * Since N is small (up to 100), we can use a frequency array of size N+1.
 * 
 * Algorithm:
 * 1. For each test case, initialize a frequency array `freq` of size N+1 to 0.
 * 2. Iterate through the input array A and increment `freq[A[i]]`.
 * 3. Iterate from color 1 to N to find the color with the maximum frequency.
 * 4. Since we iterate from 1 to N, if we encounter a frequency equal to the 
 *    current maximum, we do not update the result, thus naturally keeping 
 *    the smallest color in case of a tie.
 */

void solve() {
    int N;
    if (!(cin >> N)) return;
    
    vector<int> freq(N + 1, 0);
    for (int i = 0; i < N; ++i) {
        int color;
        cin >> color;
        if (color >= 1 && color <= N) {
            freq[color]++;
        }
    }
    
    int max_freq = -1;
    int best_color = 1;
    
    for (int i = 1; i <= N; ++i) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            best_color = i;
        }
    }
    
    cout << best_color << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}