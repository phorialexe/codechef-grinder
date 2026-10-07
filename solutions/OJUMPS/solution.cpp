#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef jumps in a sequence: +1, +2, +3, +1, +2, +3, ...
 * The sum of one full cycle (1+2+3) is 6.
 * Let's look at the points reached:
 * Start: 0
 * After 1 jump: 0 + 1 = 1
 * After 2 jumps: 1 + 2 = 3
 * After 3 jumps: 3 + 3 = 6
 * After 4 jumps: 6 + 1 = 7
 * After 5 jumps: 7 + 2 = 9
 * After 6 jumps: 9 + 3 = 12
 * 
 * The points reached are: 0, 1, 3, 6, 7, 9, 12, 13, 15, 18...
 * Taking these modulo 6:
 * 0 % 6 = 0
 * 1 % 6 = 1
 * 3 % 6 = 3
 * 6 % 6 = 0
 * 7 % 6 = 1
 * 9 % 6 = 3
 * 12 % 6 = 0
 * 
 * The reachable points modulo 6 are always 0, 1, or 3.
 * If a % 6 is 0, 1, or 3, Chef can reach the point.
 * Otherwise, he cannot.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long a;
    if (!(cin >> a)) return 0;

    long long remainder = a % 6;

    if (remainder == 0 || remainder == 1 || remainder == 3) {
        cout << "yes" << "\n";
    } else {
        cout << "no" << "\n";
    }

    return 0;
}