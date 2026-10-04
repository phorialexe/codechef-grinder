# [Chef and Table Tennis (TTENIS)](https://www.codechef.com/problems/TTENIS)

- **Difficulty Rating**: 1085
- **Solved in**: 1 attempt(s)

## Problem Summary
In this problem, we are given a string representing the sequence of points scored in a table tennis match. '1' represents a point for Chef, and '0' represents a point for the opponent. The match follows specific rules:
1. A player wins if they reach 11 points first.
2. If the score reaches 10-10, the game continues until one player leads by 2 points.
We need to determine if Chef wins ("WIN") or loses ("LOSE") based on the provided sequence.

## Intuition & Mathematical Observation
The problem states that the input string represents a **completed** match. In any completed match, the winner is simply the player who has accumulated more points than the opponent. 

While the rules regarding the 10-10 deuce scenario are specific, they mathematically guarantee that the winner will always have a higher total score than the loser by the time the match concludes. Therefore, we do not need to simulate the game point-by-point or track the deuce state; we simply need to count the total occurrences of '1's and '0's and compare them.

## Complexity Analysis
- **Time Complexity**: $O(N)$, where $N$ is the length of the string. We iterate through the string exactly once to count the points.
- **Space Complexity**: $O(N)$ to store the input string, or $O(1)$ if we process the input character by character.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * The game follows standard table tennis rules:
 * 1. First to 11 points wins, unless both reach 10 points.
 * 2. If both reach 10 points, the game continues until one player leads by 2.
 * 
 * Since the problem guarantees a valid finished match, we simply need to 
 * count the points for '1' (Chef) and '0' (Opponent) and determine the winner 
 * based on the rules provided.
 */

void solve() {
    string s;
    cin >> s;
    
    int chef_points = 0;
    int opponent_points = 0;
    
    for (char c : s) {
        if (c == '1') {
            chef_points++;
        } else {
            opponent_points++;
        }
    }
    
    // The problem guarantees a finished match.
    // In a standard game, the winner is the one who reaches 11 first,
    // or if tied at 10-10, the one who gains a 2-point lead.
    // Given the constraints and the guarantee, we can simply compare the final scores.
    if (chef_points > opponent_points) {
        cout << "WIN" << "\n";
    } else {
        cout << "LOSE" << "\n";
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