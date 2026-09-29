#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The product of an array is non-negative if:
 * 1. There is at least one zero in the array (product becomes 0).
 * 2. The number of negative integers is even.
 * 
 * If the product is negative (i.e., there are no zeros and the count of 
 * negative numbers is odd), we only need to remove one negative number 
 * to make the count of negative numbers even.
 * 
 * Algorithm:
 * 1. Count the number of zeros. If count > 0, the product is already 0 (non-negative). Return 0.
 * 2. Count the number of negative integers.
 * 3. If the count of negative integers is even, the product is positive. Return 0.
 * 4. If the count of negative integers is odd, the product is negative. Return 1.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space.
 */

void solve() {
    int N;
    cin >> N;
    
    int zero_count = 0;
    int negative_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a == 0) {
            zero_count++;
        } else if (a < 0) {
            negative_count++;
        }
    }
    
    // If there is at least one zero, the product is 0 (non-negative)
    if (zero_count > 0) {
        cout << 0 << "\n";
    } 
    // If the number of negative integers is even, the product is positive
    else if (negative_count % 2 == 0) {
        cout << 0 << "\n";
    } 
    // If the number of negative integers is odd, the product is negative
    // Removing one negative number makes the count even
    else {
        cout << 1 << "\n";
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