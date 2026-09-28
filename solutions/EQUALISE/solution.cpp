#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two numbers A and B. We can multiply either by 2 any number of times.
 * This means we can transform A into A * 2^x and B into B * 2^y.
 * We want to check if there exist non-negative integers x, y such that A * 2^x = B * 2^y.
 * 
 * This equation is equivalent to:
 * A / B = 2^(y - x)
 * 
 * Let the smaller number be min(A, B) and the larger be max(A, B).
 * We can only reach the larger number if the larger number is equal to the smaller number 
 * multiplied by some power of 2.
 * 
 * Algorithm:
 * 1. Ensure A <= B by swapping if necessary.
 * 2. While A < B, multiply A by 2.
 * 3. If A becomes equal to B, output YES, otherwise output NO.
 */

void solve() {
    int A, B;
    cin >> A >> B;
    
    if (A > B) {
        swap(A, B);
    }
    
    // Now A <= B. Keep doubling A until it reaches or exceeds B.
    while (A < B) {
        A *= 2;
    }
    
    if (A == B) {
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