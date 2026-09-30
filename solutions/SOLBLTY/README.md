# [Solubility (SOLBLTY)](https://www.codechef.com/problems/SOLBLTY)

- **Difficulty Rating**: 922
- **Solved in**: 1 attempt(s)

## Problem Summary
Given the initial temperature $X$ of 100 mL of water and its initial solubility $A$ (in grams per 100 mL), we need to calculate the maximum amount of sugar that can be dissolved in 1 Liter (1000 mL) of water at 100 degrees Celsius. The solubility increases by $B$ grams for every degree Celsius increase in temperature.

## Intuition & Mathematical Observation
1. **Temperature Difference**: The temperature increases from $X$ to 100 degrees. The total increase is $(100 - X)$ degrees.
2. **Solubility at 100°C**: Since the solubility increases by $B$ grams per degree, the new solubility at 100°C is:
   $$\text{Solubility}_{100} = A + (100 - X) \times B \text{ (grams per 100 mL)}$$
3. **Scaling to 1 Liter**: The problem asks for the amount in 1 Liter (1000 mL). Since the solubility is defined per 100 mL, we multiply the result by 10:
   $$\text{Total Sugar} = \text{Solubility}_{100} \times 10$$
4. **Constraints**: With $X \in [31, 40]$, $A \in [101, 120]$, and $B \in [1, 5]$, the values are small enough that they will not overflow a standard 32-bit integer, though `long long` is used for best practice.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case involves a constant number of arithmetic operations, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * - Initial temperature: X degrees
 * - Initial solubility: A g / 100 mL
 * - Solubility increase per degree: B g / 100 mL
 * - Target temperature: 100 degrees
 * - Total water: 1 Liter = 1000 mL
 * 
 * Solubility at 100 degrees = A + (100 - X) * B (g / 100 mL)
 * Since we have 1000 mL of water, the total amount of sugar is:
 * Total Sugar = (Solubility at 100 degrees) * (1000 / 100)
 * Total Sugar = (A + (100 - X) * B) * 10
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        long long x, a, b;
        cin >> x >> a >> b;
        
        // Calculate solubility at 100 degrees per 100 mL
        long long solubility_at_100 = a + (100 - x) * b;
        
        // Calculate total sugar for 1000 mL (1 Liter)
        // 1000 mL / 100 mL = 10 units
        long long total_sugar = solubility_at_100 * 10;
        
        cout << total_sugar << "\n";
    }
    
    return 0;
}
```