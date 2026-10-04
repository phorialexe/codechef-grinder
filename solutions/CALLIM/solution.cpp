#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Calorie Limit
 * Approach:
 * We iterate through the sweets one by one. We maintain a running sum of calories
 * consumed so far. For each sweet, we check if adding its calorie count to the 
 * current sum exceeds K. If it does, we stop immediately. Otherwise, we add it 
 * to the sum and increment our count of sweets eaten.
 * 
 * Time Complexity: O(N) per test case, where N is the number of sweets.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long current_calories = 0;
    int count = 0;
    
    for (int i = 0; i < N; ++i) {
        if (current_calories + A[i] <= K) {
            current_calories += A[i];
            count++;
        } else {
            // Cannot eat this sweet or any further sweets
            break;
        }
    }
    
    cout << count << "\n";
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