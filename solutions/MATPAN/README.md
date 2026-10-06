# [Mathison and pangrams (MATPAN)](https://www.codechef.com/problems/MATPAN)

- **Difficulty Rating**: 1127
- **Solved in**: 1 attempt(s)

## Problem Summary
We are provided with the costs of each of the 26 lowercase English letters ('a' through 'z'). We are then given a string $S$. Our goal is to make the string a **pangram** (a string containing every letter of the alphabet at least once) by adding the missing letters. We need to calculate the minimum cost required to purchase the missing letters.

## Intuition & Mathematical Observation
1. **Identify Missing Letters**: A pangram must contain every letter from 'a' to 'z'. We can iterate through the given string and mark which letters are already present using a boolean array or a frequency map.
2. **Greedy Approach**: Since we want the minimum cost, for every letter that is **not** present in the string, we must purchase it. The cost of purchasing a specific letter is fixed as provided in the input.
3. **Data Types**: The problem states that prices can be up to $1,000,000$ and the string length can be up to $50,000$. While the number of missing letters is at most 26, the total cost could potentially exceed the range of a 32-bit integer if prices were larger, so using `long long` for the `total_cost` is a safe and good practice.
4. **Efficiency**: We only need to traverse the string once ($O(N)$) and then iterate through the 26 alphabet slots ($O(1)$), making this approach highly efficient.

## Complexity Analysis
- **Time Complexity**: $O(T \times (N + 26))$, where $T$ is the number of test cases and $N$ is the length of the string. Given $N \le 50,000$ and $T \le 10$, this easily passes within the 1-second time limit.
- **Space Complexity**: $O(1)$ (or $O(26)$), as we only use a fixed-size array to store the prices and the presence status of the 26 letters.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given the prices of all 26 lowercase English letters.
 * We are given a string that might be missing some letters.
 * To make the string a pangram, we must purchase the missing letters.
 * Since we want the cheapest way, we simply identify which letters are 
 * not present in the input string and sum their corresponding prices.
 */

void solve() {
    vector<long long> prices(26);
    for (int i = 0; i < 26; ++i) {
        cin >> prices[i];
    }

    string s;
    cin >> s;

    // Track which letters are present
    vector<bool> present(26, false);
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            present[c - 'a'] = true;
        }
    }

    // Calculate total cost for missing letters
    long long total_cost = 0;
    for (int i = 0; i < 26; ++i) {
        if (!present[i]) {
            total_cost += prices[i];
        }
    }

    cout << total_cost << "\n";
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