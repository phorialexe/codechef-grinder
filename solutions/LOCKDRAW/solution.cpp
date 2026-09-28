#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three problems with points A, B, and C.
 * All three problems must be solved.
 * Let the set of points be {A, B, C}.
 * We need to partition these three values into two sets (one for Bob, one for Alice)
 * such that the sum of points in both sets is equal.
 * 
 * Let the total sum be S = A + B + C.
 * For a draw to occur, each player must have S/2 points.
 * This is only possible if S is even and there exists a subset of {A, B, C} 
 * that sums up to S/2.
 * 
 * Alternatively, since there are only 3 numbers, the possible ways to split them are:
 * 1. One player gets one problem, the other gets two.
 *    This means one of the values must equal the sum of the other two.
 *    i.e., A = B + C OR B = A + C OR C = A + B.
 * 
 * Both approaches are equivalent. If A = B + C, then A = (A+B+C)/2, which satisfies the sum condition.
 */

void solve() {
    long long a[3];
    cin >> a[0] >> a[1] >> a[2];
    
    // Sort to easily check if the largest equals the sum of the other two
    sort(a, a + 3);
    
    if (a[0] + a[1] == a[2]) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
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