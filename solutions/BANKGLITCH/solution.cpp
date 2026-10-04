#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has A units of currency 1 and B units of currency 2.
 * He can trade X units of currency 1 for Y units of currency 2.
 * Since X < Y, every trade increases the total amount of money (A + B) by (Y - X).
 * To maximize the total money, Chef should perform the trade as many times as possible.
 * The number of times he can perform the trade is limited by the amount of currency 1 he has (A).
 * Specifically, he can perform the trade floor(A / X) times.
 * 
 * Let k = floor(A / X).
 * After k trades:
 * New A = A - (k * X)
 * New B = B + (k * Y)
 * Total = New A + New B = (A - k*X) + (B + k*Y) = A + B + k*(Y - X).
 * 
 * Constraints are small (up to 100), so this O(1) calculation per test case is optimal.
 */

void solve() {
    long long A, B, X, Y;
    if (!(cin >> A >> B >> X >> Y)) return;

    // Calculate the maximum number of trades possible
    long long k = A / X;

    // Calculate the final amounts
    long long final_A = A - (k * X);
    long long final_B = B + (k * Y);

    // The total amount of money
    long long total = final_A + final_B;

    cout << total << "\n";
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