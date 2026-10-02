# [Buying New Tablet (TABLET)](https://www.codechef.com/problems/TABLET)

- **Difficulty Rating**: 1037
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given a budget $B$ and a list of $N$ tablets, each defined by its width $W$, height $H$, and price $P$. Your goal is to find the tablet with the largest screen area ($W \times H$) that you can afford (i.e., $P \le B$). If no tablet is within your budget, you must output "no tablet".

## Intuition & Mathematical Observation
The problem asks us to maximize the area $A = W \times H$ subject to the constraint $P \le B$. 

1. **Filtering**: We only care about tablets where $P \le B$. Any tablet with $P > B$ is immediately discarded.
2. **Maximization**: Among the tablets that satisfy the budget constraint, we simply need to find the maximum value of $W \times H$.
3. **Edge Case**: If the set of affordable tablets is empty, we must handle this specifically by printing "no tablet". We can track this using a boolean flag or by initializing our `max_area` variable to a value that indicates no valid tablet has been found yet (e.g., -1).

## Complexity Analysis
- **Time Complexity**: $O(T \times N)$, where $T$ is the number of test cases and $N$ is the number of tablets per test case. We iterate through each tablet exactly once per test case.
- **Space Complexity**: $O(1)$, as we only store a few variables (`max_area`, `found`, `W`, `H`, `P`) regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Buying New Tablet
 * Approach:
 * For each test case, iterate through all N tablets.
 * Check if the price P_i is less than or equal to the budget B.
 * If it is, calculate the area (W_i * H_i) and keep track of the maximum area found so far.
 * If no tablet is affordable, output "no tablet".
 * 
 * Time Complexity: O(T * N)
 * Space Complexity: O(1)
 */

void solve() {
    int N;
    long long B;
    cin >> N >> B;

    long long max_area = -1;
    bool found = false;

    for (int i = 0; i < N; ++i) {
        long long W, H, P;
        cin >> W >> H >> P;

        // Check if the tablet is within the budget
        if (P <= B) {
            long long current_area = W * H;
            // Update max_area if the current tablet is larger
            if (current_area > max_area) {
                max_area = current_area;
            }
            found = true;
        }
    }

    // Output result based on whether any affordable tablet was found
    if (!found) {
        cout << "no tablet" << "\n";
    } else {
        cout << max_area << "\n";
    }
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```