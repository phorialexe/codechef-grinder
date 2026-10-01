# [Keplers Law (KEPLERSLAW)](https://www.codechef.com/problems/KEPLERSLAW)

- **Difficulty Rating**: 992
- **Solved in**: 1 attempt(s)

## Problem Summary
The problem asks us to verify if two planets follow Kepler's Third Law of Planetary Motion. Kepler's Third Law states that the square of the orbital period ($T$) is directly proportional to the cube of the semi-major axis ($R$) of its orbit. Mathematically, this is expressed as:
$$\frac{T^2}{R^3} = K$$
Given the orbital periods ($T_1, T_2$) and semi-major axes ($R_1, R_2$) for two planets, we need to determine if $\frac{T_1^2}{R_1^3} = \frac{T_2^2}{R_2^3}$.

## Intuition & Mathematical Observation
To compare the two ratios, we could perform floating-point division. However, floating-point arithmetic often leads to precision errors. To ensure absolute accuracy, we can use **cross-multiplication**:

$$\frac{T_1^2}{R_1^3} = \frac{T_2^2}{R_2^3} \iff T_1^2 \cdot R_2^3 = T_2^2 \cdot R_1^3$$

By comparing the products $T_1^2 \cdot R_2^3$ and $T_2^2 \cdot R_1^3$ using integer arithmetic, we avoid precision issues entirely. Given the constraints (values up to 10), the resulting products will easily fit within a standard `long long` data type in C++.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations, the total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated products.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Kepler's Law
 * Kepler's 3rd Law states: T^2 / R^3 = constant
 * We need to check if (T1^2 / R1^3) == (T2^2 / R2^3)
 * To avoid floating point precision issues, we cross-multiply:
 * T1^2 * R2^3 == T2^2 * R1^3
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long t1, t2, r1, r2;
        cin >> t1 >> t2 >> r1 >> r2;

        // Calculate T1^2 * R2^3 and T2^2 * R1^3
        // Given constraints are small (up to 10), so long long is more than sufficient
        long long lhs = (t1 * t1) * (r2 * r2 * r2);
        long long rhs = (t2 * t2) * (r1 * r1 * r1);

        if (lhs == rhs) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }

    return 0;
}
```