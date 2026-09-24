# [Total Expenses (FLOW009)](https://www.codechef.com/problems/FLOW009)

- **Difficulty Rating**: 861
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to calculate the total expenses incurred for purchasing a specific quantity of items at a given price per item. If the quantity purchased exceeds 1,000, a 10% discount is applied to the total cost. The output must be formatted to 6 decimal places.

## Intuition & Mathematical Observation
1. **Conditional Logic**: The core of the problem is a simple conditional check:
   - If `quantity > 1000`: Apply a 10% discount. The formula becomes `(quantity * price) * 0.9`.
   - Otherwise: The total cost is simply `quantity * price`.
2. **Data Type Selection**: The maximum possible value for `quantity * price` is $100,000 \times 100,000 = 10,000,000,000$. Since this exceeds the limit of a standard 32-bit `int` ($\approx 2 \times 10^9$), we must use `double` or `long long`. Given the requirement for floating-point precision in the output, `double` is the most suitable choice.
3. **Formatting**: To meet the requirement of 6 decimal places, we use `fixed` and `setprecision(6)` from the `<iomanip>` library.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Total Expenses
 * Logic:
 * If quantity > 1000, apply a 10% discount.
 * Total Expense = quantity * price * (1 - 0.10) = quantity * price * 0.9
 * Otherwise, Total Expense = quantity * price.
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
```