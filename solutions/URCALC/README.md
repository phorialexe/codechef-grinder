# [Program Your Own CALCULATOR (URCALC)](https://www.codechef.com/problems/URCALC)

- **Difficulty Rating**: 1028
- **Solved in**: 2 attempt(s)

## Problem Summary
The task is to build a simple calculator that takes two numbers ($a$ and $b$) and an operator ($c$) as input. The program must perform the arithmetic operation corresponding to the operator ('+', '-', '*', or '/') and output the result. The division operation requires high precision to satisfy the problem's constraints.

## Intuition & Mathematical Observation
1. **Data Types**: Since the problem involves division and requires precision, we must use `double` instead of `int` to store the input numbers.
2. **Precision**: The problem requires the output to be accurate to a specific decimal place. Using `std::fixed` and `std::setprecision(6)` from the `<iomanip>` library ensures that the output meets the required floating-point precision tolerance.
3. **Logic**: A simple `if-else` or `switch` statement is sufficient to handle the four basic arithmetic operations.
4. **Common Pitfall**: In the first attempt, failing to format the output correctly often leads to "Wrong Answer" verdicts because the default precision of `cout` may truncate or round the result incorrectly for competitive programming judges.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The program performs a constant number of arithmetic operations regardless of the input values.
- **Space Complexity**: $O(1)$ — We only use a fixed amount of memory to store two `double` variables and one `char`.

## Solution Code

```cpp
#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Problem: URCALC - Program Your Own CALCULATOR
 * The primary issue in the previous attempt was the lack of explicit 
 * floating-point formatting. Using fixed and setprecision ensures that 
 * division results meet the required 10^-6 precision tolerance.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;
    char c;

    // Reading inputs
    if (!(cin >> a >> b >> c)) return 0;

    // Set precision to ensure floating point results are accurate
    cout << fixed << setprecision(6);

    // Perform operation based on the operator C
    if (c == '+') {
        cout << (a + b) << endl;
    } else if (c == '-') {
        cout << (a - b) << endl;
    } else if (c == '*') {
        cout << (a * b) << endl;
    } else if (c == '/') {
        // Division requires floating point result
        cout << (a / b) << endl;
    }

    return 0;
}
```