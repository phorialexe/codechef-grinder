# [Chef and Icecream (CHFICRM)](https://www.codechef.com/problems/CHFICRM)

- **Difficulty Rating**: 1269
- **Solved in**: 2 attempt(s)

## Problem Summary
Chef sells ice cream for Rs. 5. Each customer arrives with either a Rs. 5, Rs. 10, or Rs. 15 coin. Since Chef starts with no money, he must provide the exact change to each customer using the coins he has collected from previous customers. We need to determine if Chef can successfully serve all customers in the queue.

## Intuition & Mathematical Observation
This is a greedy problem. We need to track the inventory of Rs. 5 and Rs. 10 coins:

1.  **If the customer pays Rs. 5**: No change is needed. Chef simply adds this to his collection (`count5++`).
2.  **If the customer pays Rs. 10**: Chef must return Rs. 5. This is only possible if `count5 > 0`. If successful, he loses a Rs. 5 coin and gains a Rs. 10 coin.
3.  **If the customer pays Rs. 15**: Chef must return Rs. 10. He has two options:
    *   **Priority 1**: Give one Rs. 10 coin (if `count10 > 0`). This is optimal because Rs. 10 coins are less versatile than Rs. 5 coins.
    *   **Priority 2**: If no Rs. 10 coin is available, give three Rs. 5 coins (Wait, the problem states the ice cream is Rs. 5, so for a Rs. 15 payment, he needs to return Rs. 10. This can be done with two Rs. 5 coins). If `count5 >= 2`, he uses them.
    *   If neither option is available, the transaction fails.

By always prioritizing the use of a Rs. 10 coin when returning Rs. 10 change, we preserve the more flexible Rs. 5 coins for future transactions.

## Complexity Analysis
- **Time Complexity**: $O(N)$ per test case, where $N$ is the number of customers. We iterate through the list of customers exactly once.
- **Space Complexity**: $O(1)$, as we only use a few integer variables to keep track of the coin counts regardless of the input size.

## Solution Code

```cpp
#include <iostream>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * We need to maintain the count of Rs. 5 and Rs. 10 coins currently held by Chef.
 * - If customer pays 5: Chef keeps it (count5++).
 * - If customer pays 10: Chef needs 5 back. If count5 > 0, count5--, count10++. Else, fail.
 * - If customer pays 15: Chef needs 10 back.
 *      - Prefer giving a 10-rupee coin if available (count10--).
 *      - Otherwise, give two 5-rupee coins (count5 -= 2).
 *      - If neither is possible, fail.
 */

void solve() {
    int N;
    cin >> N;
    int count5 = 0;
    int count10 = 0;
    bool possible = true;

    for (int i = 0; i < N; ++i) {
        int coin;
        cin >> coin;

        // If we already failed, we just consume the remaining input
        if (!possible) continue;

        if (coin == 5) {
            count5++;
        } else if (coin == 10) {
            if (count5 >= 1) {
                count5--;
                count10++;
            } else {
                possible = false;
            }
        } else if (coin == 15) {
            // Try to give 10 back first (using a 10-rupee coin)
            if (count10 >= 1) {
                count10--;
            } 
            // Otherwise, try to give 10 back using two 5-rupee coins
            else if (count5 >= 2) {
                count5 -= 2;
            } else {
                possible = false;
            }
        }
    }

    if (possible) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
```