#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A valid phone number consists of exactly 5 digits with no leading zeros.
 * This means the number must be in the range [10000, 99999].
 * 
 * Given N items at cost X, the total bill is B = N * X.
 * We need to check if 10000 <= B <= 99999.
 * 
 * Constraints:
 * 1 <= N, X <= 1000
 * Max B = 1000 * 1000 = 1,000,000.
 * This fits within a standard 32-bit integer, but using long long is safer.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long n, x;
        cin >> n >> x;
        
        long long total_bill = n * x;
        
        // Check if the bill is exactly 5 digits and has no leading zeros.
        // A number has 5 digits if it is >= 10000 and <= 99999.
        // Since the smallest 5-digit number is 10000, it cannot have a leading zero.
        if (total_bill >= 10000 && total_bill <= 99999) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}