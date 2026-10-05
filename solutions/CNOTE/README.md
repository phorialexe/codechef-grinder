# [Chef and Notebooks (CNOTE)](https://www.codechef.com/problems/CNOTE)

- **Difficulty Rating**: 1255
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef needs a total of $X$ pages for his notebook. He currently has $Y$ pages. He has a budget of $K$ rupees to buy a new notebook. There are $N$ available notebooks in the shop, where the $i$-th notebook has $P_i$ pages and costs $C_i$ rupees. We need to determine if Chef can fulfill his requirement of having at least $X$ pages in total by purchasing at most one notebook within his budget.

## Intuition & Mathematical Observation
1. **Calculate Deficit**: Chef already has $Y$ pages and needs $X$. The number of additional pages required is $R = \max(0, X - Y)$. If $X \le Y$, Chef already has enough pages, but the problem implies he wants to buy a notebook; however, the logic holds: if $R=0$, any notebook with $C_i \le K$ works (or he is already "Lucky").
2. **Filtering Criteria**: For each notebook $(P_i, C_i)$, Chef can choose it if and only if:
   - $P_i \ge R$ (The notebook provides enough pages to cover the deficit).
   - $C_i \le K$ (The cost is within his budget).
3. **Input Handling**: It is critical to iterate through all $N$ notebooks even if a suitable one is found early, to ensure the input stream is correctly cleared for subsequent test cases.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of notebooks. Given the constraints, the total time complexity is $O(\sum N)$, which is approximately $10^5$ to $10^6$ operations, fitting well within the 1-second time limit.
- **Space Complexity**: $O(1)$, as we only store a few variables and process the input on the fly without needing to store the list of notebooks in an array.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Chef needs X pages total. He has Y pages.
 * Pages needed = max(0, X - Y).
 * He has K budget.
 * He needs to find if there exists a notebook (Pi, Ci) such that:
 * 1. Pi >= pages_needed
 * 2. Ci <= K
 * 
 * Complexity: O(N) per test case. Total O(Sum of N), which is 10^6.
 * This fits well within the 1-second time limit.
 */

void solve() {
    int X, Y, K, N;
    if (!(cin >> X >> Y >> K >> N)) return;

    int pages_needed = (X > Y) ? (X - Y) : 0;
    bool found = false;

    for (int i = 0; i < N; ++i) {
        int P, C;
        cin >> P >> C;
        // We must read all N lines regardless of whether we found a match
        // to ensure the input stream is correctly positioned for the next test case.
        if (!found && P >= pages_needed && C <= K) {
            found = true;
        }
    }

    if (found) {
        cout << "LuckyChef" << "\n";
    } else {
        cout << "UnluckyChef" << "\n";
    }
}

int main() {
    // Fast I/O is crucial for 10^6 inputs
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}
```