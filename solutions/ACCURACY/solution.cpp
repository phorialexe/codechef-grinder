#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Let C be the number of correct answers and W be the number of wrong answers.
 * Marks X = 3*C - W.
 * We want to minimize W such that there exists a non-negative integer C 
 * where 3*C - W = X, and C + W <= 100.
 * 
 * From X = 3*C - W, we have W = 3*C - X.
 * Since W must be non-negative, 3*C >= X.
 * To minimize W, we need to find the smallest C such that 3*C >= X.
 * This C is ceil(X / 3.0).
 * Let C_min = ceil(X / 3.0).
 * Then W = 3 * C_min - X.
 * 
 * Example: X = 32
 * 3*C >= 32 => C >= 10.66 => C = 11.
 * W = 3*11 - 32 = 33 - 32 = 1.
 * 
 * Example: X = 100
 * 3*C >= 100 => C >= 33.33 => C = 34.
 * W = 3*34 - 100 = 102 - 100 = 2.
 * 
 * This logic holds because W = (3 - (X % 3)) % 3.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;
        
        // Calculate the remainder when divided by 3
        int rem = x % 3;
        
        // If x is divisible by 3, remainder is 0, so 0 wrong answers needed.
        // If remainder is 1, we need 2 wrong answers to reach the next multiple of 3 (e.g., 1 -> 3-1=2, 4 -> 6-4=2).
        // If remainder is 2, we need 1 wrong answer to reach the next multiple of 3 (e.g., 2 -> 3-2=1, 5 -> 6-5=1).
        if (rem == 0) {
            cout << 0 << "\n";
        } else if (rem == 1) {
            cout << 2 << "\n";
        } else {
            cout << 1 << "\n";
        }
    }
    
    return 0;
}