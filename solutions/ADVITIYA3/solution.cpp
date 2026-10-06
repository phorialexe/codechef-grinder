#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N jars, each with A_i cookies. We need to choose one jar i such that
 * A_i >= K (to ensure each of the K children gets at least 1 cookie).
 * If we choose jar i, the number of cookies distributed is the largest multiple 
 * of K that is <= A_i. Let this be M * K.
 * The number of wasted cookies is A_i - (M * K), which is simply A_i % K.
 * We want to minimize this value over all jars where A_i >= K.
 * If no jar satisfies A_i >= K, the answer is -1.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long min_waste = -1;
    bool possible = false;
    
    for (int i = 0; i < N; ++i) {
        if (A[i] >= K) {
            long long current_waste = A[i] % K;
            if (!possible || current_waste < min_waste) {
                min_waste = current_waste;
                possible = true;
            }
        }
    }
    
    if (!possible) {
        cout << -1 << "\n";
    } else {
        cout << min_waste << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}