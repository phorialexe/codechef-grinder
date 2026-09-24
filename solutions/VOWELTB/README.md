# [Is it a VOWEL or CONSONANT (VOWELTB)](https://www.codechef.com/problems/VOWELTB)

- **Difficulty Rating**: 840
- **Solved in**: 1 attempt(s)

## Problem Summary
The objective is to determine whether a given single uppercase English alphabet character is a **Vowel** or a **Consonant**. In the English alphabet, the vowels are defined as 'A', 'E', 'I', 'O', and 'U'. All other uppercase letters are considered consonants.

## Intuition & Mathematical Observation
Since the input is restricted to a single uppercase character, we do not need complex data structures. We can simply check the input character against the set of known vowels. 

- If the character matches any of `{'A', 'E', 'I', 'O', 'U'}`, the output should be `"Vowel"`.
- Otherwise, the character is guaranteed to be a consonant, so the output should be `"Consonant"`.

Using a simple `if-else` conditional statement or a `switch` statement is the most efficient way to handle this logic.

## Complexity Analysis
- **Time Complexity**: $O(1)$ — The operation involves a constant number of comparisons regardless of the input character.
- **Space Complexity**: $O(1)$ — We only store a single character variable, requiring constant extra space.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Is it a VOWEL or CONSONANT
 * The problem asks to identify if a given uppercase character is a vowel (A, E, I, O, U)
 * or a consonant.
 * 
 * Time Complexity: O(1) per character
 * Space Complexity: O(1)
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char c;
    if (!(cin >> c)) return 0;

    // Check if the character is one of the vowels
    if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
        cout << "Vowel" << "\n";
    } else {
        cout << "Consonant" << "\n";
    }

    return 0;
}
```