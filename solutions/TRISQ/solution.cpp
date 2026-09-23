#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * For a right-angled isosceles triangle of base B, we can fit squares of size 2x2.
 * The number of squares that can fit in each row follows a pattern:
 * If B=4, rows = 1. If B=6, rows = 1+2=3. If B=8, rows = 1+2+3=6.
 * Let n = B / 2. The number of squares is the sum of integers from 1 to (n-1).
 * Formula: (n * (n - 1)) / 2, where n = B / 2.
 */

void solve() {
    int B;
    cin >> B;
    
    // Calculate n = B / 2
    int n = B / 2;
    
    // The number of squares is the sum of (n-1) + (n-2) + ... + 1
    // which is (n-1) * n / 2
    int result = (n * (n - 1)) / 2;
    
    cout << result << endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }

    return 0;
}