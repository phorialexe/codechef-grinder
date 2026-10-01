#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * For a coin of value n, we have two choices:
 * 1. Sell it for n dollars.
 * 2. Exchange it for coins of value n/2, n/3, and n/4, and sell those.
 * 
 * The recurrence relation is:
 * f(n) = max(n, f(n/2) + f(n/3) + f(n/4))
 * 
 * Since n can be up to 10^9, we cannot use a simple array for memoization.
 * However, notice that for small n, the values are small. We can use a map
 * or a simple array for small values (e.g., up to 1,000,000) to speed up 
 * the recursion.
 */

map<long long, long long> memo;

long long solve(long long n) {
    if (n == 0) return 0;
    if (n < 12) return n; // Base case: for n < 12, n/2 + n/3 + n/4 <= n
    
    // Check memoization table
    if (n <= 1000000 && memo.count(n)) return memo[n];
    if (n > 1000000 && memo.count(n)) return memo[n];
    
    long long res = max(n, solve(n / 2) + solve(n / 3) + solve(n / 4));
    
    return memo[n] = res;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n;
    // The problem states "several test cases (not more than 10)".
    // We read until EOF.
    while (cin >> n) {
        cout << solve(n) << "\n";
    }
    
    return 0;
}