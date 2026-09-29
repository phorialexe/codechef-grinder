#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Problem Analysis:
 * Scheme 1: 100 + 4 * X
 * Scheme 2: 300
 * We need to find min(100 + 4 * X, 300).
 * 
 * Debugging Note: The previous attempt incorrectly assumed multiple test cases.
 * The problem input format specifies a single integer X.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (cin >> X) {
        long long scheme1 = 100 + (4LL * X);
        long long scheme2 = 300;
        
        cout << min(scheme1, scheme2) << endl;
    }
    
    return 0;
}