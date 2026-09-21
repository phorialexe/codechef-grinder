#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The fest Advitiya is held on the 16th, 17th, and 18th of February.
 * Given an input N (1 <= N <= 18), we need to check if N is 16, 17, or 18.
 * If N is in {16, 17, 18}, output "ADVITIYA".
 * Otherwise, output "WAITING FOR ADVITIYA".
 * 
 * Time Complexity: O(1) per test case.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    if (!(cin >> N)) return 0;

    // Check if the date falls within the range [16, 18]
    if (N >= 16 && N <= 18) {
        cout << "ADVITIYA" << "\n";
    } else {
        cout << "WAITING FOR ADVITIYA" << "\n";
    }

    return 0;
}