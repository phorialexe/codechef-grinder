#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * 1. Row constraint: If there are M seats in a row, we need at least one empty seat between 
 *    two people. This is equivalent to picking seats at indices 1, 3, 5, ...
 *    The number of people in one row is ceil(M / 2.0).
 *    Using integer arithmetic: (M + 1) / 2.
 * 
 * 2. Column constraint: If there are N rows, we need at least one empty row between 
 *    two occupied rows. This is equivalent to picking rows 1, 3, 5, ...
 *    The number of rows that can be occupied is ceil(N / 2.0).
 *    Using integer arithmetic: (N + 1) / 2.
 * 
 * 3. Total tickets: Since the choices are independent, the total number of tickets 
 *    is the product of the number of occupied rows and the number of people per row.
 *    Total = ((N + 1) / 2) * ((M + 1) / 2).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, m;
        cin >> n >> m;

        // Calculate max rows and max seats per row using integer division
        long long rows = (n + 1) / 2;
        long long seats_per_row = (m + 1) / 2;

        // The result is the product of the two
        long long max_tickets = rows * seats_per_row;

        cout << max_tickets << "\n";
    }

    return 0;
}