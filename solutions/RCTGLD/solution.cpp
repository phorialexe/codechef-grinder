#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A rectangle with sides 'a' and 'b' (where a, b are integers) has a perimeter 
 * P = 2 * (a + b).
 * The problem states we have N units of ink, so 2 * (a + b) <= N.
 * This simplifies to a + b <= N / 2.
 * Since a and b must be integers, a + b <= floor(N / 2).
 * Let S = floor(N / 2). We want to maximize area A = a * b subject to a + b <= S.
 * To maximize the product of two numbers with a fixed sum, the numbers should be 
 * as close to each other as possible.
 * 
 * If S is even, a = S/2, b = S/2. Area = (S/2) * (S/2).
 * If S is odd, a = S/2, b = S/2 + 1. Area = (S/2) * (S/2 + 1).
 * 
 * Constraints: N <= 1000.
 * If N < 4, we cannot form a rectangle with integral sides (minimum perimeter is 2*(1+1)=4).
 * The area is 0 for N < 4.
 */

void solve() {
    int N;
    cin >> N;
    
    if (N < 4) {
        cout << 0 << "\n";
        return;
    }
    
    int S = N / 2;
    int a = S / 2;
    int b = S - a;
    
    long long area = (long long)a * b;
    cout << area << "\n";
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