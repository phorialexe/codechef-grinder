#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: International Education Day!
 * The problem asks to calculate the maximum of (A * C) and (B * C).
 * Given the constraints 1 <= A, B, C <= 10, the result will fit in a standard integer.
 * However, using long long is a good practice to prevent overflow in similar problems.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case based on the input format,
    // but standard competitive programming practice is to handle input as specified.
    // Reading A, B, and C.
    long long A, B, C;
    if (!(cin >> A >> B >> C)) return 0;

    // Calculate total sales for Chef and Chefina
    long long chef_sales = A * C;
    long long chefina_sales = B * C;

    // Output the maximum of the two
    cout << max(chef_sales, chefina_sales) << "\n";

    return 0;
}