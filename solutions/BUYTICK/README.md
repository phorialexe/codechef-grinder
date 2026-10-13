# [Buying Tickets (BUYTICK)](https://www.codechef.com/problems/BUYTICK)

- **Difficulty Rating**: 944
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given $N$ seats, each with a specific cost $A_i$. A binary string $S$ of length $N$ indicates the availability of these seats, where $S_i = '0'$ means the seat is available and $S_i = '1'$ means it is occupied. We need to purchase exactly $K$ available seats such that the total cost is minimized. If there are fewer than $K$ available seats, we must output -1.

## Intuition & Mathematical Observation
To minimize the total cost of purchasing $K$ seats, we should always prioritize the seats with the lowest individual costs. 

1. **Filtering**: First, we iterate through the input array $A$ and the string $S$ simultaneously. We collect the costs of all seats where $S_i == '0'$ into a separate list.
2. **Validation**: If the count of available seats is less than $K$, it is impossible to fulfill the requirement, so we output -1.
3. **Greedy Selection**: If we have enough seats, we sort the list of available costs in non-decreasing order. By picking the first $K$ elements from this sorted list, we guarantee the minimum possible sum.
4. **Data Types**: Since the sum of costs might exceed the range of a 32-bit integer, we use `long long` for the `min_cost` variable to prevent overflow.

## Complexity Analysis
- **Time Complexity**: $O(T \times N \log N)$, where $T$ is the number of test cases and $N$ is the number of seats. The sorting step dominates the complexity per test case. Given $N \le 100$, this approach is highly efficient.
- **Space Complexity**: $O(N)$ to store the costs of the available seats.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N seats with costs A_i.
 * A binary string S tells us which seats are available (S_i == '0').
 * We need to select K seats from the available ones such that the total cost is minimized.
 * 
 * Strategy:
 * 1. Identify all available seats (where S_i == '0').
 * 2. Store the costs of these available seats in a list.
 * 3. If the number of available seats is less than K, output -1.
 * 4. Otherwise, sort the costs of available seats in non-decreasing order.
 * 5. Sum the first K costs and output the result.
 */

void solve() {
    int N, K;
    cin >> N >> K;
    
    vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    string S;
    cin >> S;
    
    vector<int> available_costs;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            available_costs.push_back(A[i]);
        }
    }
    
    // Check if we have enough seats to fulfill the request
    if (available_costs.size() < (size_t)K) {
        cout << -1 << "\n";
    } else {
        // Sort to pick the K cheapest seats
        sort(available_costs.begin(), available_costs.end());
        long long min_cost = 0;
        for (int i = 0; i < K; ++i) {
            min_cost += available_costs[i];
        }
        cout << min_cost << "\n";
    }
}

int main() {
    // Fast I/O
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