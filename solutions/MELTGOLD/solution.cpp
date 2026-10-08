#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Initial temperature = Y
 * Melting point = X
 * After minute 1: Temp = Y + 1
 * After minute 2: Temp = Y + 1 + 2
 * After minute n: Temp = Y + (1 + 2 + ... + n)
 * Formula for sum of first n integers: n(n+1)/2
 * We need the smallest n such that: Y + n(n+1)/2 >= X
 * Which simplifies to: n(n+1)/2 >= X - Y
 * Let D = X - Y. We need n(n+1)/2 >= D.
 * Since X, Y <= 10^5, D <= 10^5.
 * The maximum value of n will be around sqrt(2 * 10^5) approx 450.
 * A simple loop is efficient enough for 10^5 test cases.
 */

void solve() {
    long long X, Y;
    cin >> X >> Y;
    
    long long diff = X - Y;
    long long current_temp_increase = 0;
    int minutes = 0;
    
    while (current_temp_increase < diff) {
        minutes++;
        current_temp_increase += minutes;
    }
    
    cout << minutes << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}