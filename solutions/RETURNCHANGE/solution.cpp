#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The cost X is rounded to the nearest multiple of 10.
 * If the last digit is 5 or greater, it rounds up.
 * If the last digit is less than 5, it rounds down.
 * This is equivalent to rounding X/10 to the nearest integer and multiplying by 10.
 * In C++, adding 5 to X and performing integer division by 10 (i.e., (X + 5) / 10) 
 * effectively performs this rounding logic.
 * Finally, the amount returned is 100 - rounded_cost.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x;
        cin >> x;

        // Calculate the rounded cost
        // (x + 5) / 10 performs integer division, effectively rounding to nearest 10
        // Multiplying by 10 gives the rounded value.
        int rounded_cost = ((x + 5) / 10) * 10;

        // The amount returned is 100 minus the rounded cost
        int returned_amount = 100 - rounded_cost;

        cout << returned_amount << "\n";
    }

    return 0;
}