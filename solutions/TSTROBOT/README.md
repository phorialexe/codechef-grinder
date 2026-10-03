# [Testing Robot (TSTROBOT)](https://www.codechef.com/problems/TSTROBOT)

- **Difficulty Rating**: 1124
- **Solved in**: 1 attempt(s)

## Problem Summary
A robot starts at a given coordinate $X$ on a 1D number line. It receives a sequence of $N$ commands, where each command is either 'L' (move one unit left, $X \to X-1$) or 'R' (move one unit right, $X \to X+1$). The goal is to determine the total number of **distinct** integer coordinates visited by the robot throughout the entire process, including the starting position.

## Intuition & Mathematical Observation
The problem requires tracking unique positions visited over time. Since the robot can revisit the same coordinate multiple times (e.g., moving 'L' then 'R' returns the robot to the starting point), a simple counter is insufficient.

- **Data Structure Choice**: A `std::set` in C++ is ideal here because it automatically handles duplicate values. By inserting every position the robot occupies into the set, we ensure that each coordinate is stored only once.
- **Process**:
    1. Initialize the set with the starting position $X$.
    2. Iterate through the command string $S$.
    3. Update the `current_pos` based on the character ('L' or 'R').
    4. Insert the updated `current_pos` into the set.
    5. The final answer is simply the `size()` of the set.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$ per test case. We iterate through $N$ commands, and each insertion into a `std::set` takes $O(\log K)$ time, where $K$ is the number of unique positions visited (at most $N+1$).
- **Space Complexity**: $O(N)$. In the worst case, the robot visits a new coordinate with every move, requiring us to store up to $N+1$ distinct positions in the set.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The robot starts at position X.
 * It executes N commands.
 * We need to count the number of distinct integer coordinates visited.
 * Since N is small (up to 100), we can track all visited positions using a set.
 * The set will automatically handle duplicates, and the size of the set
 * will be the number of distinct points visited.
 */

void solve() {
    int N;
    long long X;
    cin >> N >> X;
    string S;
    cin >> S;

    // Use a set to store unique visited coordinates
    set<long long> visited;
    long long current_pos = X;
    
    // The robot starts at X, so X is visited initially.
    visited.insert(current_pos);

    for (char move : S) {
        if (move == 'L') {
            current_pos--;
        } else if (move == 'R') {
            current_pos++;
        }
        // Insert the new position; set handles duplicates automatically
        visited.insert(current_pos);
    }

    // The number of unique elements in the set is the answer
    cout << visited.size() << "\n";
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}
```