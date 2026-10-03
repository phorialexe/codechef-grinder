# [Body Mass Index (BMI)](https://www.codechef.com/problems/BMI)

- **Difficulty Rating**: 845
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to calculate the Body Mass Index (BMI) of a person given their mass ($M$) in kilograms and height ($H$) in meters. The formula provided is $BMI = \frac{M}{H^2}$. Based on the resulting BMI value, we must categorize the person into one of four categories:
1. **Underweight**: $BMI \le 18$
2. **Healthy**: $19 \le BMI \le 24$
3. **Overweight**: $25 \le BMI \le 29$
4. **Obese**: $BMI \ge 30$

## Intuition & Mathematical Observation
The problem states that $H^2$ will always divide $M$ perfectly, which guarantees that the BMI will result in an integer. This simplifies the implementation significantly as we do not need to handle floating-point precision or rounding errors. We can use standard integer division (`/`) to compute the BMI and then use a simple `if-else` ladder to determine the correct category.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. For each test case, we perform a constant number of arithmetic operations and comparisons, resulting in $O(1)$ per test case.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the calculated BMI, regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Body Mass Index
 * BMI = M / H^2
 * Constraints: 1 <= M <= 10^4, 1 <= H <= 10^2
 * Since H^2 divides M, BMI will always be an integer.
 * 
 * Categories:
 * 1: BMI <= 18
 * 2: 19 <= BMI <= 24
 * 3: 25 <= BMI <= 29
 * 4: BMI >= 30
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long m, h;
        cin >> m >> h;
        
        // Calculate BMI. Since H^2 divides M, integer division is safe.
        long long bmi = m / (h * h);
        
        if (bmi <= 18) {
            cout << 1 << "\n";
        } else if (bmi >= 19 && bmi <= 24) {
            cout << 2 << "\n";
        } else if (bmi >= 25 && bmi <= 29) {
            cout << 3 << "\n";
        } else {
            // bmi >= 30
            cout << 4 << "\n";
        }
    }
    
    return 0;
}
```