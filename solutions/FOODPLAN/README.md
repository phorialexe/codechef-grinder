# [Online or Offline (FOODPLAN)](https://www.codechef.com/problems/FOODPLAN)

- **Difficulty Rating**: 713
- **Solved in**: 3 attempt(s)

## Problem Summary
You are given the price of food when ordered online ($N$) and the price when dining at the restaurant ($M$). Online orders receive a 10% discount. You need to determine whether it is cheaper to order online, dine at the restaurant, or if the cost is the same.

## Intuition & Mathematical Observation
The cost of ordering online after a 10% discount is calculated as:
$$\text{Online Cost} = N - (0.10 \times N) = 0.9 \times N$$

We need to compare $0.9 \times N$ with $M$. To avoid potential precision issues associated with floating-point arithmetic, we can multiply both sides of the comparison by 10:
- Compare $9 \times N$ with $10 \times M$.

By using this scaled integer comparison:
- If $9N < 10M$, the online price is cheaper.
- If $9N > 10M$, the dining price is cheaper.
- If $9N = 10M$, both prices are equal.

## Complexity Analysis
- **Time Complexity**: $O(T)$, where $T$ is the number of test cases. Each test case performs a constant number of arithmetic operations.
- **Space Complexity**: $O(1)$, as we only use a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem: FOODPLAN
 * Logic: 
 * Online price after 10% discount = N - (N * 0.1) = 0.9 * N
 * We compare 0.9 * N with M.
 * To avoid floating point issues, multiply by 10:
 * Compare 9 * N with 10 * M.
 */

void solve() {
    int N, M;
    if (!(cin >> N >> M)) return;

    // Using scaled values to perform comparison using integers
    int online_cost_scaled = 9 * N;
    int dining_cost_scaled = 10 * M;

    if (online_cost_scaled < dining_cost_scaled) {
        cout << "ONLINE" << endl;
    } else if (online_cost_scaled > dining_cost_scaled) {
        cout << "DINING" << endl;
    } else {
        cout << "EITHER" << endl;
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```