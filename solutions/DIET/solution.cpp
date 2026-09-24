#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs K grams of protein each day.
 * He buys A_i grams on day i.
 * He stores the surplus (A_i - K) to use on future days.
 * If at any point the total available protein (stored + current day's purchase)
 * is less than K, he fails on that day.
 * 
 * Constraints:
 * N <= 100, K <= 10^6, A_i <= 10^6.
 * Total protein can exceed 2^31-1, so use long long for safety, 
 * though with N=100 and A_i=10^6, the max sum is 10^8, which fits in int.
 * Using long long is good practice.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long stored = 0;
    bool possible = true;
    int fail_day = -1;
    
    for (int i = 0; i < N; ++i) {
        // Add current day's protein to stored
        stored += A[i];
        
        // Check if we can eat K grams
        if (stored < K) {
            possible = false;
            fail_day = i + 1;
            break;
        } else {
            // Consume K grams
            stored -= K;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO " << fail_day << "\n";
    }
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