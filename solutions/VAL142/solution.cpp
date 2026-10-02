#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find if there exist 7 positive integers a1, a2, ..., a7 such that:
 * a1 >= 1
 * a2 >= 2 * a1
 * a3 >= 2 * a2
 * ...
 * a7 >= 2 * a6
 * And the sum a1 + a2 + ... + a7 <= X.
 * 
 * To minimize the sum, we should pick the smallest possible values:
 * a1 = 1
 * a2 = 2 * a1 = 2
 * a3 = 2 * a2 = 4
 * a4 = 2 * a3 = 8
 * a5 = 2 * a4 = 16
 * a6 = 2 * a5 = 32
 * a7 = 2 * a6 = 64
 * 
 * The minimum sum is 1 + 2 + 4 + 8 + 16 + 32 + 64 = 127.
 * If X >= 127, Chef can always plan the gifts.
 * If X < 127, it is impossible to satisfy the condition because any other set 
 * of values would result in a sum strictly greater than 127.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x;
        cin >> x;
        
        // The minimum sum for 7 days following the rule is 127.
        // 1 + 2 + 4 + 8 + 16 + 32 + 64 = 127
        if (x >= 127) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }
    
    return 0;
}