#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem asks for the parity of the sum of binary digits of N.
 * This is equivalent to finding the population count (number of set bits) of N.
 * If the number of set bits is even, output "EVEN".
 * If the number of set bits is odd, output "ODD".
 * 
 * C++ provides a built-in function __builtin_popcount(n) which returns the 
 * number of set bits in an integer. Since N <= 10^9, it fits in a 32-bit 
 * integer, so __builtin_popcount is sufficient.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        // __builtin_popcount returns the number of 1s in the binary representation
        int set_bits = __builtin_popcount(n);
        
        // Check if the count is even or odd
        if (set_bits % 2 == 0) {
            cout << "EVEN" << "\n";
        } else {
            cout << "ODD" << "\n";
        }
    }
    
    return 0;
}