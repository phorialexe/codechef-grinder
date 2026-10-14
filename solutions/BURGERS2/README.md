# [Hungry Chef (BURGERS2)](https://www.codechef.com/problems/BURGERS2)

- **Difficulty Rating**: 1187
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef wants to buy exactly $N$ burgers. There are two types of burgers available:
1. **Normal Burger**: Costs $X$ rupees.
2. **Premium Burger**: Costs $Y$ rupees.

Given a total budget of $R$ rupees, determine if it is possible to buy exactly $N$ burgers. If possible, output the number of normal and premium burgers such that the total cost does not exceed $R$. If it is impossible, output -1.

## Intuition & Mathematical Observation
Let $n_{normal}$ be the number of normal burgers and $n_{premium}$ be the number of premium burgers. We are given:
1. $n_{normal} + n_{premium} = N$
2. $X \cdot n_{normal} + Y \cdot n_{premium} \le R$

Substituting $n_{normal} = N - n_{premium}$ into the second equation:
$$X(N - n_{premium}) + Y \cdot n_{premium} \le R$$
$$X \cdot N - X \cdot n_{premium} + Y \cdot n_{premium} \le R$$
$$n_{premium}(Y - X) \le R - X \cdot N$$

Since $Y > X$, we can isolate $n_{premium}$:
$$n_{premium} \le \frac{R - X \cdot N}{Y - X}$$

**Key Logic:**
- If $R < X \cdot N$, even buying the cheapest burgers (all normal) exceeds the budget, so it is impossible (output -1).
- Otherwise, we calculate the maximum possible number of premium burgers we can afford using the derived formula.
- Since we must have exactly $N$ burgers, $n_{premium}$ cannot exceed $N$. Thus, $n_{premium} = \min(N, \lfloor \frac{R - X \cdot N}{Y - X} \rfloor)$.
- Once $n_{premium}$ is found, $n_{normal} = N - n_{premium}$.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the solution involves simple arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and results.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to find n_normal and n_premium such that:
 * n_normal + n_premium = N
 * X * n_normal + Y * n_premium <= R
 * 
 * Derived formula: n_premium <= (R - X * N) / (Y - X)
 */

void solve() {
    long long X, Y, N, R;
    cin >> X >> Y >> N >> R;

    // Minimum cost to buy N burgers is N * X (all normal)
    if (R < N * X) {
        cout << -1 << "\n";
        return;
    }

    // Maximum number of premium burgers we can afford
    // n_premium * (Y - X) <= R - X * N
    long long max_premium = (R - N * X) / (Y - X);

    // We can't buy more than N burgers total
    if (max_premium > N) {
        max_premium = N;
    }

    long long n_premium = max_premium;
    long long n_normal = N - n_premium;

    cout << n_normal << " " << n_premium << "\n";
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