#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef has two options:
 * 1. Buy a single television: Cost = 1000
 * 2. Buy N toys: Cost = N * 200
 * 
 * We need to find the minimum of these two values: min(1000, N * 200).
 * Given constraints: 1 <= N <= 10.
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    // The problem description implies a single integer N as input.
    // If the problem format requires handling multiple test cases, 
    // we check if there's an input to read.
    if (cin >> N) {
        long long cost_tv = 1000;
        long long cost_toys = (long long)N * 200;
        
        cout << min(cost_tv, cost_toys) << "\n";
    }

    return 0;
}