#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N friends, each providing a color C_i.
 * We want to order them such that the number of color changes (jolts) is minimized.
 * 
 * Let the sequence of colors be S_1, S_2, ..., S_N.
 * A jolt occurs when:
 * 1. The first friend is visited (none -> S_1): 1 jolt.
 * 2. For any i from 1 to N-1, if S_i != S_{i+1}: 1 jolt.
 * 
 * To minimize jolts, we should group all identical colors together.
 * If we have K distinct colors present in the input, we can arrange the friends
 * such that all friends of color X_1 come first, then all friends of color X_2,
 * and so on, up to color X_K.
 * 
 * The sequence of colors will look like:
 * (X_1, X_1, ..., X_1), (X_2, X_2, ..., X_2), ..., (X_K, X_K, ..., X_K)
 * 
 * Jolts:
 * - Initial visit: 1 jolt.
 * - Transitions between groups: K - 1 jolts.
 * Total jolts = 1 + (K - 1) = K.
 * 
 * Therefore, the minimum number of jolts is simply the number of distinct colors.
 */

void solve() {
    int N;
    cin >> N;
    set<int> distinct_colors;
    for (int i = 0; i < N; ++i) {
        int c;
        cin >> c;
        distinct_colors.insert(c);
    }
    
    // The number of jolts is equal to the number of unique colors.
    cout << distinct_colors.size() << "\n";
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