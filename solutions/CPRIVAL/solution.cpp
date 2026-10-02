#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Rivalry
 * The problem asks us to compare the final ratings of two individuals, 
 * Dominater and Everule, after their initial ratings are modified by 
 * given rating changes.
 * 
 * Final Rating of Dominater = R1 + D1
 * Final Rating of Everule = R2 + D2
 * 
 * We compare these two values and print the name of the person with the higher rating.
 * Constraints are small enough that standard integers suffice, but long long 
 * is used for safety.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long R1, R2;
    long long D1, D2;

    // Reading input
    if (!(cin >> R1 >> R2)) return 0;
    if (!(cin >> D1 >> D2)) return 0;

    // Calculating final ratings
    long long final_dominater = R1 + D1;
    long long final_everule = R2 + D2;

    // Comparing and outputting the result
    if (final_dominater > final_everule) {
        cout << "Dominater" << "\n";
    } else {
        cout << "Everule" << "\n";
    }

    return 0;
}