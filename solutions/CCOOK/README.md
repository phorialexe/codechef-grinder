# [Chef and Cook-Off (CCOOK)](https://www.codechef.com/problems/CCOOK)

- **Difficulty Rating**: 961
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to categorize a developer based on the number of problems they have solved out of 5. Each input line contains 5 integers (either 0 or 1), where 1 represents a solved problem. Based on the total count of 1s, we must output the corresponding title:
- 0 solved: "Beginner"
- 1 solved: "Junior Developer"
- 2 solved: "Middle Developer"
- 3 solved: "Senior Developer"
- 4 solved: "Hacker"
- 5 solved: "Jeff Dean"

## Intuition & Mathematical Observation
The problem is a straightforward implementation task. Since there are exactly 5 problems per developer, the number of solved problems can only range from 0 to 5. 

We can iterate through each of the $N$ test cases, maintain a running sum (or counter) for the number of 1s in the input row, and use a series of `if-else` statements or a lookup array to map the count to the required string. Because the input size is small and the logic is linear, a simple loop processing each row independently is sufficient.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the number of competitors. For each competitor, we perform a constant number of operations (reading 5 integers and performing a comparison).
- **Space Complexity**: $O(1)$, as we only store a few integer variables regardless of the input size.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Chef and Cook-Off
 * The task is to count the number of solved problems (sum of 1s in the input row)
 * and map that count to the corresponding developer level.
 * 
 * Time Complexity: O(N) where N is the number of competitors.
 * Space Complexity: O(1) as we process each line independently.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    while (n--) {
        int solved_count = 0;
        for (int i = 0; i < 5; ++i) {
            int val;
            cin >> val;
            if (val == 1) {
                solved_count++;
            }
        }

        // Mapping the count to the corresponding level
        if (solved_count == 0) {
            cout << "Beginner" << "\n";
        } else if (solved_count == 1) {
            cout << "Junior Developer" << "\n";
        } else if (solved_count == 2) {
            cout << "Middle Developer" << "\n";
        } else if (solved_count == 3) {
            cout << "Senior Developer" << "\n";
        } else if (solved_count == 4) {
            cout << "Hacker" << "\n";
        } else if (solved_count == 5) {
            cout << "Jeff Dean" << "\n";
        }
    }

    return 0;
}
```