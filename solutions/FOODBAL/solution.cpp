#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Food Balance
 * The goal is to compare the absolute difference between fat and protein for two dishes.
 * Let D1 = |F1 - P1| and D2 = |F2 - P2|.
 * If D1 < D2, output "First".
 * If D2 < D1, output "Second".
 * If D1 == D2, output "Both".
 * 
 * Constraints are small (1 to 100), so standard int is sufficient.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int f1, p1, f2, p2;
    // The problem description implies a single line of input per test case.
    // Based on standard competitive programming formats, we read the four integers.
    if (!(cin >> f1 >> p1 >> f2 >> p2)) return 0;

    // Calculate absolute differences
    int diff1 = abs(f1 - p1);
    int diff2 = abs(f2 - p2);

    // Compare and output result
    if (diff1 < diff2) {
        cout << "First" << "\n";
    } else if (diff2 < diff1) {
        cout << "Second" << "\n";
    } else {
        cout << "Both" << "\n";
    }

    return 0;
}