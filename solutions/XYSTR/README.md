# [Chef and String (XYSTR)](https://www.codechef.com/problems/XYSTR)

- **Difficulty Rating**: 1124
- **Solved in**: 1 attempt(s)

## Problem Summary
We are given a string consisting of characters 'x' and 'y', representing students. We want to form the maximum number of adjacent pairs such that each pair consists of one 'x' and one 'y'. Each student can belong to at most one pair. The goal is to find the maximum number of such pairs that can be formed.

## Intuition & Mathematical Observation
This problem is a classic application of the **Greedy Algorithm**. 

To maximize the total number of pairs, we should process the string from left to right. When we encounter two adjacent students:
1. If they are different (one 'x' and one 'y'), we should pair them immediately. This is optimal because pairing them now doesn't prevent us from forming other pairs later that we couldn't have formed otherwise. After pairing, we skip both students by incrementing our index by 2.
2. If they are the same (both 'x' or both 'y'), we cannot pair them. We must move to the next student (increment index by 1) to see if a valid pair can be formed starting from the next position.

By always taking the first available valid pair, we ensure that we don't "waste" a student who could have been part of a pair, thus achieving the global maximum.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We traverse the string exactly once.
- **Space Complexity**: $O(N)$ to store the input string.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given a string of 'x's and 'y's. We want to form the maximum number of 
 * adjacent pairs (boy, girl). Since each student can be in at most one pair, 
 * this is a classic greedy problem.
 * 
 * Strategy:
 * Iterate through the string from left to right. If the current student and the 
 * next student form a pair (one is 'x' and the other is 'y'), we pair them up 
 * and skip the next student (increment index by 2). Otherwise, move to the 
 * next student (increment index by 1).
 */

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    int pairs = 0;
    
    for (int i = 0; i < n - 1; ) {
        // Check if current student and next student are different
        if (s[i] != s[i + 1]) {
            pairs++;
            // Move index by 2 because both students are now paired
            i += 2;
        } else {
            // Move index by 1 to check the next possible pair
            i++;
        }
    }
    
    cout << pairs << "\n";
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