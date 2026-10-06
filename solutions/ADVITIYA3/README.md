# [Cookie Day (ADVITIYA3)](https://www.codechef.com/problems/ADVITIYA3)

- **Difficulty Rating**: 995
- **Solved in**: 1 attempt(s)

## Problem Summary
You are given $N$ jars, each containing $A_i$ cookies, and $K$ children. You must select exactly one jar to distribute cookies such that every child receives an equal number of cookies. The goal is to minimize the number of leftover (wasted) cookies. If it is impossible to give at least one cookie to each of the $K$ children from any single jar, output -1.

## Intuition & Mathematical Observation
1. **Feasibility**: To distribute cookies equally among $K$ children, a jar must contain at least $K$ cookies ($A_i \ge K$). If no jar satisfies this condition, it is impossible to perform the distribution, hence the answer is -1.
2. **Calculating Waste**: If we choose a jar with $A_i$ cookies, the number of cookies each child receives is $\lfloor A_i / K \rfloor$. The total number of cookies distributed is $K \times \lfloor A_i / K \rfloor$. The remaining cookies (waste) is simply $A_i \pmod K$.
3. **Optimization**: We need to iterate through all jars where $A_i \ge K$, calculate the remainder $A_i \pmod K$ for each, and track the minimum value found.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, as we iterate through the list of jars exactly once.
- **Space Complexity**: $O(N)$ to store the input array (or $O(1)$ if we process the input values on the fly).

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N jars, each with A_i cookies. We need to choose one jar i such that
 * A_i >= K (to ensure each of the K children gets at least 1 cookie).
 * If we choose jar i, the number of cookies distributed is the largest multiple 
 * of K that is <= A_i. Let this be M * K.
 * The number of wasted cookies is A_i - (M * K), which is simply A_i % K.
 * We want to minimize this value over all jars where A_i >= K.
 * If no jar satisfies A_i >= K, the answer is -1.
 */

void solve() {
    int N;
    long long K;
    cin >> N >> K;
    
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    long long min_waste = -1;
    bool possible = false;
    
    for (int i = 0; i < N; ++i) {
        if (A[i] >= K) {
            long long current_waste = A[i] % K;
            // If this is the first valid jar or we found a smaller remainder
            if (!possible || current_waste < min_waste) {
                min_waste = current_waste;
                possible = true;
            }
        }
    }
    
    if (!possible) {
        cout << -1 << "\n";
    } else {
        cout << min_waste << "\n";
    }
}

int main() {
    // Fast I/O setup
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