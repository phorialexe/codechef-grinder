#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Yearly Phone
 * The task is to take a year X and output 'K' followed by the last two digits of X.
 * Since 1973 <= X <= 2024, the last two digits can be extracted using the modulo operator (X % 100).
 * We must ensure that if the last two digits are less than 10 (e.g., 2005 -> 05), 
 * we print the leading zero. Using printf with "%02d" or string manipulation is ideal.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    if (!(cin >> X)) return 0;

    // Extract the last two digits
    int lastTwo = X % 100;

    // Print 'K' followed by the two digits, ensuring leading zero if necessary
    cout << "K";
    if (lastTwo < 10) {
        cout << "0" << lastTwo << "\n";
    } else {
        cout << lastTwo << "\n";
    }

    return 0;
}