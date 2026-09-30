#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N bottles, each with capacity X.
 * We have a total volume of water S = sum(A_i).
 * Since we can transfer water freely between bottles without spillage,
 * we want to pack the total volume S into the minimum number of bottles.
 * 
 * Each bottle can hold at most X liters.
 * If we have S liters of water, the number of bottles required is the smallest 
 * integer k such that k * X >= S.
 * This is equivalent to ceil(S / X).
 * Using integer arithmetic, ceil(S / X) can be calculated as (S + X - 1) / X.
 * 
 * Constraints:
 * N <= 100, X <= 1000, A_i <= X.
 * Total water S <= 100 * 1000 = 100,000.
 * This fits comfortably in a standard 32-bit integer, but we use long long 
 * for safety as per instructions.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    
    long long total_water = 0;
    for (int i = 0; i < N; ++i) {
        long long a;
        cin >> a;
        total_water += a;
    }
    
    // We need to find the minimum number of bottles k such that k * X >= total_water.
    // k = ceil(total_water / X)
    // Using integer division: (total_water + X - 1) / X
    long long min_bottles = (total_water + X - 1) / X;
    
    cout << min_bottles << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    
    return 0;
}