# [HOW MANY DIGITS DO I HAVE (HOWMANY)](https://www.codechef.com/problems/HOWMANY)

- **Difficulty Rating**: 908
- **Solved in**: 1 attempt(s)

## Problem Summary
The task is to determine the number of digits in a given integer $N$. Specifically, we need to output:
- "1" if the number has 1 digit.
- "2" if the number has 2 digits.
- "3" if the number has 3 digits.
- "More than 3 digits" if the number has 4 or more digits.

The input $N$ is guaranteed to be a non-negative integer.

## Intuition & Mathematical Observation
While the problem could be solved using mathematical operations (like repeatedly dividing by 10 or using logarithms), the simplest and most robust approach is to treat the input as a **string**.

1. **String Representation**: By reading the input as a `std::string`, we can immediately determine the number of digits by checking the length of the string using the `.length()` method.
2. **Conditional Logic**: Once we have the length, we simply map the length to the required output strings using a series of `if-else` statements.
3. **Efficiency**: Since the input size is small, reading as a string is highly efficient and avoids potential overflow issues or complex base-10 logic.

## Complexity Analysis
- **Time Complexity**: $O(D)$, where $D$ is the number of digits in the input. Since we are reading the input once and checking its length, the operation is effectively linear relative to the number of digits.
- **Space Complexity**: $O(D)$, as we store the input number as a string of length $D$.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: HOW MANY DIGITS DO I HAVE
 * Approach: Read the input as a string to easily determine the number of digits.
 * This is the most robust way to handle the digit count for any integer input.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n;
    if (!(cin >> n)) return 0;

    int len = n.length();

    if (len == 1) {
        cout << "1" << "\n";
    } else if (len == 2) {
        cout << "2" << "\n";
    } else if (len == 3) {
        cout << "3" << "\n";
    } else {
        cout << "More than 3 digits" << "\n";
    }

    return 0;
}
```