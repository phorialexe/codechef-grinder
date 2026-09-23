#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and Parole
 * Logic: Chef needs at least 7 days to be released.
 * If X >= 7, output "Yes", otherwise "No".
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single integer input X.
    // Although the prompt mentions "Handle multiple test cases", 
    // the problem description says "The first and only line of input consists of an integer X".
    // We will read X directly.
    
    long long X;
    if (cin >> X) {
        if (X >= 7) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}