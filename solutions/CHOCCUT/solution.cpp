#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an N x M chocolate bar. We need to cut it into two equal pieces
 * along a grid line.
 * 
 * Total area = N * M.
 * For the pieces to be equal, each piece must have an area of (N * M) / 2.
 * This implies that (N * M) must be even.
 * 
 * If we cut horizontally, we split the N rows into two parts: N1 and N2,
 * such that N1 + N2 = N. The area of the two pieces would be (N1 * M) and (N2 * M).
 * For these to be equal, N1 * M = N2 * M, which implies N1 = N2.
 * This is possible if N is even (cut at N/2).
 * 
 * If we cut vertically, we split the M columns into two parts: M1 and M2,
 * such that M1 + M2 = M. The area of the two pieces would be (N * M1) and (N * M2).
 * For these to be equal, N * M1 = N * M2, which implies M1 = M2.
 * This is possible if M is even (cut at M/2).
 * 
 * Thus, we can divide the chocolate if N is even OR M is even.
 * The only case where this is not possible is if both N and M are odd.
 * Exception: If N=1 and M=1, the total area is 1, which cannot be divided into 
 * two equal integer pieces. However, the logic "N is even or M is even" 
 * correctly handles this (1 is odd, 1 is odd -> No).
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // If either dimension is even, we can cut it in half.
        // If both are odd, the total area is odd, so we cannot split into two equal integer pieces.
        // Also, if N=1 and M=1, N*M=1, which is odd, so "No" is correct.
        if (n % 2 == 0 || m % 2 == 0) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}