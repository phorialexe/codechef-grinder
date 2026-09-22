# [Codechef Round (CODECHEF)](https://www.codechef.com/problems/CODECHEF)

- **Difficulty Rating**: 232
- **Solved in**: 2 attempt(s)

## Problem Summary
The problem asks us to determine if a given day of the week, represented by an integer $N$, corresponds to a "Codechef round." According to the problem statement, Codechef rounds are held specifically on Wednesdays. Given that the days are numbered such that Wednesday is the 4th day of the week, we must output "YES" if $N = 4$ and "NO" otherwise.

## Intuition & Mathematical Observation
The problem provides a direct mapping:
- Sunday = 1
- Monday = 2
- Tuesday = 3
- **Wednesday = 4**
- Thursday = 5
- Friday = 6
- Saturday = 7

Since the condition for a Codechef round is strictly tied to Wednesday, the logic simplifies to a basic equality check. If the input integer $N$ is equal to 4, the condition is satisfied; for any other integer between 1 and 7, it is not.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The solution performs a single comparison operation regardless of the input value.
- **Space Complexity**: $O(1)$ — We only use a single integer variable to store the input, requiring constant extra space.

## Solution Code

```cpp
#include <iostream>

using namespace std;

/**
 * Problem: CODECHEF
 * Logic: The problem states that Codechef rounds are held on Wednesday, 
 * which is the 4th day of the week (Sunday=1, Monday=2, Tuesday=3, Wednesday=4).
 * We need to output "YES" if N == 4, and "NO" otherwise.
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        if (n == 4) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
```