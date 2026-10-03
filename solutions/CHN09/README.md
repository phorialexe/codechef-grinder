# [Malvika is peculiar about color of balloons (CHN09)](https://www.codechef.com/problems/CHN09)

- **Difficulty Rating**: 988
- **Solved in**: 1 attempt(s)

## Problem Summary
Malvika has a collection of balloons, each colored either amber ('a') or brass ('b'). She wants all the balloons in her collection to be of the same color. She can perform an operation where she changes the color of any single balloon to the other color. The goal is to find the minimum number of operations required to make all balloons the same color.

## Intuition & Mathematical Observation
Since there are only two possible colors ('a' and 'b'), there are only two target states:
1. **All balloons become 'a'**: To achieve this, we must change every 'b' balloon into an 'a'. The number of operations required is equal to the total count of 'b's in the string.
2. **All balloons become 'b'**: To achieve this, we must change every 'a' balloon into a 'b'. The number of operations required is equal to the total count of 'a's in the string.

To minimize the operations, we simply calculate the frequency of both characters and take the minimum of the two:
$$\text{Result} = \min(\text{count of 'a'}, \text{count of 'b'})$$

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the length of the string. We iterate through the string exactly once to count the occurrences of each character.
- **Space Complexity**: $O(N)$ to store the input string. If we processed the input character by character without storing the string, this could be reduced to $O(1)$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Malvika wants all balloons to be the same color.
 * There are only two colors: 'a' (amber) and 'b' (brass).
 * To make all balloons 'a', we must paint all 'b' balloons to 'a'.
 * The number of operations required would be the count of 'b's.
 * To make all balloons 'b', we must paint all 'a' balloons to 'b'.
 * The number of operations required would be the count of 'a's.
 * To minimize the operations, we take the minimum of (count of 'a's, count of 'b's).
 */

void solve() {
    string s;
    cin >> s;
    
    int count_a = 0;
    int count_b = 0;
    
    for (char c : s) {
        if (c == 'a') {
            count_a++;
        } else if (c == 'b') {
            count_b++;
        }
    }
    
    // The minimum flips required is the minimum of the two counts
    cout << min(count_a, count_b) << "\n";
}

int main() {
    // Fast I/O setup
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