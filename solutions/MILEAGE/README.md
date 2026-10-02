# [Mileage matters (MILEAGE)](https://www.codechef.com/problems/MILEAGE)

- **Difficulty Rating**: 831
- **Solved in**: 1 attempt(s)

## Problem Summary
The goal is to determine the most cost-effective fuel for a trip of distance $N$ kilometers. We are given:
- **Petrol**: Price $X$ per liter, mileage $A$ km/liter.
- **Diesel**: Price $Y$ per liter, mileage $B$ km/liter.

We need to output "PETROL" if petrol is cheaper, "DIESEL" if diesel is cheaper, or "ANY" if the costs are identical.

## Intuition & Mathematical Observation
The cost for petrol is $\frac{N}{A} \times X$ and the cost for diesel is $\frac{N}{B} \times Y$. 

To avoid floating-point precision errors, we compare the two fractions:
$$\frac{N \times X}{A} \text{ vs } \frac{N \times Y}{B}$$

By cross-multiplying (multiplying both sides by $A \times B$), we get:
$$(N \times X \times B) \text{ vs } (N \times Y \times A)$$

Since $N$ is a positive constant, we can simplify the comparison to:
$$(X \times B) \text{ vs } (Y \times A)$$

Using this cross-multiplication method ensures we work entirely with integers, preventing any precision issues that might arise from division.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Distance to travel: N
 * Petrol: Price X, Mileage A km/litre.
 * Cost for petrol = (N / A) * X
 * Diesel: Price Y, Mileage B km/litre.
 * Cost for diesel = (N / B) * Y
 * 
 * To avoid floating point precision issues, we compare:
 * (N * X) / A  vs  (N * Y) / B
 * Multiplying both sides by (A * B), we compare:
 * (N * X * B)  vs  (N * Y * A)
 */

void solve() {
    long long N, X, Y, A, B;
    cin >> N >> X >> Y >> A >> B;

    // Calculate scaled costs to avoid floating point division
    long long petrol_cost_scaled = N * X * B;
    long long diesel_cost_scaled = N * Y * A;

    if (petrol_cost_scaled < diesel_cost_scaled) {
        cout << "PETROL" << "\n";
    } else if (diesel_cost_scaled < petrol_cost_scaled) {
        cout << "DIESEL" << "\n";
    } else {
        cout << "ANY" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
```