# [Utkarsh and Placement tests (UTKPLC)](https://www.codechef.com/problems/UTKPLC)

- **Difficulty Rating**: 886
- **Solved in**: 2 attempt(s)

## Problem Summary
Utkarsh has received job offers from two companies out of three possible options. He has a specific preference order for these three companies. Given the preference order and the two companies he received offers from, determine which company he should choose based on his preference.

## Intuition & Mathematical Observation
The problem asks us to select the company that appears earlier in a given preference list. Since there are only three companies, we can assign a "rank" to each company based on its position in the preference list (e.g., the first company gets rank 0, the second rank 1, and the third rank 2).

By mapping the company characters to these integer ranks, the problem reduces to a simple comparison: if `rank[offer1] < rank[offer2]`, then `offer1` is preferred; otherwise, `offer2` is preferred. Using an array of size 256 (indexed by the ASCII value of the characters) provides an $O(1)$ lookup time, which is more efficient and cleaner than using a hash map or multiple `if-else` statements.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. We perform a constant number of operations (mapping 3 characters and comparing 2 values).
- **Space Complexity**: $O(1)$. We use a fixed-size array of 256 integers regardless of the input.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem: Utkarsh and Placement tests
 * Approach:
 * We are given a preference order of 3 companies. We map each company to its 
 * rank (0, 1, 2) and compare the ranks of the two offers received.
 * Using a simple array for mapping is faster and safer than unordered_map.
 */

void solve() {
    char p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    
    char x, y;
    cin >> x >> y;
    
    // Map each company to its preference rank (0, 1, 2)
    // Using an array indexed by the character's ASCII value
    int rank[256];
    rank[p1] = 0;
    rank[p2] = 1;
    rank[p3] = 2;
    
    // Compare the ranks of the two offers
    if (rank[x] < rank[y]) {
        cout << x << "\n";
    } else {
        cout << y << "\n";
    }
}

int main() {
    // Fast I/O
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