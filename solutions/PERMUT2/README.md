# [Ambiguous Permutations (PERMUT2)](https://www.codechef.com/problems/PERMUT2)

- **Difficulty Rating**: 853
- **Solved in**: 1 attempt(s)

## Problem Summary
A permutation $P$ of size $n$ is called **ambiguous** if the permutation $P$ is equal to its inverse. The inverse of a permutation $P$ is defined as a permutation $Q$ where $Q[P[i]] = i$ for all $1 \le i \le n$. In simpler terms, if the value at index $i$ is $j$ (i.e., $P[i] = j$), then the value at index $j$ must be $i$ (i.e., $P[j] = i$). We need to determine if a given permutation is ambiguous.

## Intuition & Mathematical Observation
The definition of an inverse permutation states that if $P[i] = j$, then $Q[j] = i$. For the permutation to be ambiguous, $P$ must be equal to $Q$. Substituting $P$ for $Q$, the condition becomes:
$$P[P[i]] = i$$

This must hold true for every index $i$ from $1$ to $n$. 
- If we encounter any index $i$ where $P[P[i]] \neq i$, the permutation is immediately disqualified as "not ambiguous."
- If the condition holds for all $i$, the permutation is "ambiguous."

Since the input size $n$ can be up to $100,000$, we can iterate through the array once to verify this condition, making the solution highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(n)$ per test case, where $n$ is the size of the permutation. We perform a single pass to read the input and a single pass to verify the condition.
- **Space Complexity**: $O(n)$ to store the permutation array of size $n+1$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * A permutation P is ambiguous if P[i] = inverse_P[i] for all i.
 * The inverse permutation is defined such that if P[i] = j, then inverse_P[j] = i.
 * Therefore, the condition for ambiguity is:
 * P[P[i]] = i (using 1-based indexing).
 * 
 * Given the constraints (n up to 100,000), an O(n) approach per test case is optimal.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    // The problem states the input ends with a zero.
    while (cin >> n && n != 0) {
        // Using a vector to store the permutation. 
        // Size n+1 to accommodate 1-based indexing.
        vector<int> p(n + 1);
        for (int i = 1; i <= n; ++i) {
            cin >> p[i];
        }

        bool ambiguous = true;
        // Check the condition: P[P[i]] == i
        // If P[i] = j, then the inverse permutation has i at position j.
        // For the permutation to be ambiguous, the value at position j in the 
        // original permutation must be i.
        for (int i = 1; i <= n; ++i) {
            if (p[p[i]] != i) {
                ambiguous = false;
                break;
            }
        }

        if (ambiguous) {
            cout << "ambiguous" << "\n";
        } else {
            cout << "not ambiguous" << "\n";
        }
    }

    return 0;
}
```