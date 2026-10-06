# [Farmer Feb (POTATOES)](https://www.codechef.com/problems/POTATOES)

- **Difficulty Rating**: 1148
- **Solved in**: 1 attempt(s)

## Problem Summary
Farmer Feb has $x$ potatoes and his friend has $y$ potatoes. They decide to plant $z$ more potatoes such that the total number of potatoes $(x + y + z)$ becomes a prime number. Given $x$ and $y$, we need to find the smallest positive integer $z$ ($z \ge 1$) that satisfies this condition.

## Intuition & Mathematical Observation
1. **Constraints**: The input values $x$ and $y$ are at most 1000. Therefore, the sum $x + y$ is at most 2000.
2. **Search Space**: We are looking for the smallest prime number strictly greater than $x + y$. According to Bertrand's Postulate, there is always a prime number between $n$ and $2n$. For $n=2000$, the next prime is 2003. Thus, $z$ will be a very small integer, making a linear search for $z$ starting from 1 highly efficient.
3. **Primality Test**: Since we need to check if $(x + y + z)$ is prime, we can implement a standard $O(\sqrt{N})$ primality test. Given the small constraints, this approach will easily pass within the time limits for 1000 test cases.

## Complexity Analysis
- **Time Complexity**: $O(T \cdot \sqrt{S} \cdot K)$, where $T$ is the number of test cases, $S$ is the maximum possible sum ($\approx 2000$), and $K$ is the average number of increments needed to find the next prime. Since $K$ is very small, this is effectively $O(T \sqrt{S})$.
- **Space Complexity**: $O(1)$, as we only use a few variables for calculation and do not store any large data structures.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given x and y, and we need to find the smallest integer z >= 1 
 * such that (x + y + z) is a prime number.
 * 
 * Constraints:
 * 1 <= T <= 1000
 * 1 <= x, y <= 1000
 * The maximum sum x + y is 2000. The next prime after 2000 is 2003.
 * So z will be at most 2003 - 2 = 2001.
 */

// Function to check if a number is prime in O(sqrt(n))
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int x, y;
        cin >> x >> y;
        
        int sum = x + y;
        int z = 1;
        
        // Find the smallest z >= 1 such that sum + z is prime
        while (true) {
            if (isPrime(sum + z)) {
                cout << z << "\n";
                break;
            }
            z++;
        }
    }
    
    return 0;
}
```