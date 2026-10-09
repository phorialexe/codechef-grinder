#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs to complete N minutes of work.
 * Pigeons arrive at every K-th minute (K, 2K, 3K, ...).
 * We need to find the total time T such that the number of minutes 
 * in the range [1, T] that are NOT multiples of K is exactly N.
 * 
 * Let f(T) be the number of minutes Chef can work in T minutes.
 * f(T) = T - floor(T / K).
 * We want the smallest T such that f(T) >= N.
 * 
 * Since N and K are small (up to 100), we can simply iterate or use 
 * the property that the number of work minutes is T - (T/K).
 * Given the constraints, a simple loop or direct calculation works.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    
    int work_done = 0;
    int current_minute = 0;
    
    while (work_done < N) {
        current_minute++;
        // If the current minute is not a multiple of K, Chef works
        if (current_minute % K != 0) {
            work_done++;
        }
    }
    
    cout << current_minute << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}