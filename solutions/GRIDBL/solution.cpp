#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an N x M grid. We want to cover it with 2x2 tiles and 1x1 tiles.
 * To minimize 1x1 tiles, we should maximize the number of 2x2 tiles.
 * 
 * A 2x2 tile covers 2 rows and 2 columns.
 * If N is even and M is even, we can cover the entire grid with 2x2 tiles (0 tiles of 1x1).
 * If N is odd and M is even, we will have one row left over (M cells). Since M is even, 
 * we can cover these M cells with 1x2 tiles? No, we only have 2x2 and 1x1.
 * Actually, if N is odd, we have a row of M cells. We can fill these with 1x1 tiles.
 * So if N is odd, we need M tiles of 1x1.
 * If M is odd, we need N tiles of 1x1.
 * If both are odd, we have a row of M cells and a column of N cells, 
 * but they overlap at one corner.
 * 
 * Logic:
 * Total area = N * M.
 * If N is even and M is even: 0 tiles of 1x1.
 * If N is odd and M is even: M tiles of 1x1.
 * If N is even and M is odd: N tiles of 1x1.
 * If N is odd and M is odd: (N-1) + (M-1) + 1 = N + M - 1 tiles of 1x1.
 * 
 * Simplified:
 * If N % 2 != 0 and M % 2 != 0: result is N + M - 1
 * Else if N % 2 != 0: result is M
 * Else if M % 2 != 0: result is N
 * Else: 0
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        if (n % 2 == 0 && m % 2 == 0) {
            cout << 0 << "\n";
        } else if (n % 2 != 0 && m % 2 != 0) {
            cout << (n + m - 1) << "\n";
        } else if (n % 2 != 0) {
            cout << m << "\n";
        } else {
            cout << n << "\n";
        }
    }

    return 0;
}