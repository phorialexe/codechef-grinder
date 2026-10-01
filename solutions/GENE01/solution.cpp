#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The problem states that brown (R) is the most common, blue (B) is next, 
 * and green (G) is the rarest.
 * The child's eye color is the most common of the two parents' eye colors.
 * 
 * Hierarchy: R > B > G
 * 
 * Logic:
 * If either parent is 'R', the child is 'R'.
 * Else if either parent is 'B', the child is 'B'.
 * Else (both are 'G'), the child is 'G'.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c1, c2;
    if (!(cin >> c1 >> c2)) return 0;

    // Determine the dominant color based on the hierarchy R > B > G
    if (c1 == 'R' || c2 == 'R') {
        cout << "R" << "\n";
    } else if (c1 == 'B' || c2 == 'B') {
        cout << "B" << "\n";
    } else {
        // Both must be 'G'
        cout << "G" << "\n";
    }

    return 0;
}