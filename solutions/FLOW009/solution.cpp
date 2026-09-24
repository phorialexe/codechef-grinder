#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Total Expenses
 * Logic:
 * If quantity > 1000, apply a 10% discount.
 * Total Expense = quantity * price * (1 - 0.10) = quantity * price * 0.9
 * Otherwise, Total Expense = quantity * price.
 * 
 * Constraints:
 * quantity, price <= 100,000.
 * Max product = 100,000 * 100,000 = 10,000,000,000.
 * This exceeds the range of a 32-bit signed integer (approx 2*10^9),
 * so we must use 'double' or 'long long' for calculations.
 * Since the output requires floating point precision, 'double' is appropriate.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    // Set output precision to 6 decimal places as per sample output
    cout << fixed << setprecision(6);

    while (t--) {
        double quantity, price;
        cin >> quantity >> price;

        double total_expense;
        if (quantity > 1000) {
            // Apply 10% discount
            total_expense = (quantity * price) * 0.9;
        } else {
            // No discount
            total_expense = quantity * price;
        }

        cout << total_expense << "\n";
    }

    return 0;
}