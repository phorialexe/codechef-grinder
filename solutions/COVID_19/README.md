# [Covid and Theatre Tickets (COVID_19)](https://www.codechef.com/problems/COVID_19)

- **Difficulty Rating**: 1077
- **Solved in**: 1 attempt(s)

## Problem Summary
Given a theatre with $N$ rows and $M$ seats per row, we need to determine the maximum number of tickets that can be sold under the constraint that no two people can sit adjacent to each other, either in the same row or in the same column. This implies that every occupied seat must have an empty seat between it and any other occupied seat horizontally and vertically.

## Intuition & Mathematical Observation
To maximize the number of people, we should place them in a grid-like pattern where every second seat in every second row is occupied.

1.  **Row Constraint**: If we have $N$ rows, we can occupy rows $1, 3, 5, \dots$. The number of rows we can use is $\lceil N / 2 \rceil$. Using integer arithmetic, this is calculated as `(N + 1) / 2`.
2.  **Column Constraint**: Similarly, for each row, we can occupy seats $1, 3, 5, \dots$. The number of seats per row we can use is $\lceil M / 2 \rceil$. Using integer arithmetic, this is calculated as `(M + 1) / 2`.
3.  **Total Calculation**: Since the row selection and seat selection are independent, the total number of people (tickets) is the product of the number of available rows and the number of available seats per row.

**Formula**: 
$$\text{Total} = \left\lfloor \frac{N+1}{2} \right\rfloor \times \left\lfloor \frac{M+1}{2} \right\rfloor$$

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case is solved in $O(1)$ time using basic arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
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
```