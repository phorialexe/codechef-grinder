# [Selling Insurance (AGENTCHEF)](https://www.codechef.com/problems/AGENTCHEF)

- **Difficulty Rating**: 732
- **Solved in**: 1 attempt(s)

## Problem Summary
An insurance agent earns a commission of 20% on each insurance policy sold, where each policy costs $X$ dollars. The agent wants to earn at least 100 dollars. We need to determine the minimum number of insurance policies the agent must sell to reach or exceed this target.

## Intuition & Mathematical Observation
1. **Commission Calculation**: The commission per policy is $20\%$ of $X$, which is $0.2 \times X$ or $\frac{X}{5}$.
2. **Setting up the Inequality**: Let $n$ be the number of policies sold. We need the total commission to be at least 100:
   $$n \times \left(\frac{X}{5}\right) \geq 100$$
3. **Simplifying**: Multiply both sides by 5:
   $$n \times X \geq 500$$
   $$n \geq \frac{500}{X}$$
4. **Integer Constraint**: Since the number of policies $n$ must be an integer, we take the ceiling of the result:
   $$n = \lceil \frac{500}{X} \rceil$$
5. **Implementation Trick**: In integer arithmetic, the ceiling of $\frac{a}{b}$ can be calculated using the formula `(a + b - 1) / b`. Thus, our formula becomes `(500 + X - 1) / X`.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as the calculation involves only basic arithmetic operations. For $T$ test cases, the total time complexity is $O(T)$.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each insurance costs X dollars.
 * Commission per insurance = 20% of X = 0.2 * X = X / 5.
 * We need to find the minimum number of insurances 'n' such that:
 * n * (X / 5) >= 100
 * n * X >= 500
 * n >= 500 / X
 * 
 * Since n must be an integer, n = ceil(500 / X).
 * Using integer arithmetic, ceil(a / b) can be calculated as (a + b - 1) / b.
 * Here, n = (500 + X - 1) / X.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long x;
        cin >> x;
        
        // Calculate minimum insurances needed
        // Using the formula (500 + x - 1) / x for ceiling division
        long long ans = (500 + x - 1) / x;
        
        cout << ans << "\n";
    }

    return 0;
}
```