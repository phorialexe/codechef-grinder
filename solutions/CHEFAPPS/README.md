# [Chef and his Apps (CHEFAPPS)](https://www.codechef.com/problems/CHEFAPPS)

- **Difficulty Rating**: 702
- **Solved in**: 1 attempt(s)

## Problem Summary
Chef has a phone with a total storage capacity of $S$. Currently, two apps are installed on the phone, occupying $X$ and $Y$ amount of storage respectively. Chef wants to install a new app that requires $Z$ amount of storage. We need to determine the minimum number of existing apps (0, 1, or 2) that Chef must uninstall to free up enough space for the new app.

## Intuition & Mathematical Observation
The total free storage currently available on the phone is calculated as:
$$\text{Free Storage} = S - (X + Y)$$

We evaluate the requirement $Z$ against the available space using a greedy approach:
1. **Case 0 (Delete nothing):** If the current free storage is already greater than or equal to $Z$, no apps need to be deleted.
2. **Case 1 (Delete one app):** If the current free storage is insufficient, we should try to delete the larger of the two apps to maximize the newly freed space. If $(\text{Free Storage} + \max(X, Y)) \ge Z$, then deleting one app is sufficient.
3. **Case 2 (Delete both apps):** If even after deleting the larger app the space is insufficient, we must delete both apps. Since the problem implies the new app can fit if both are removed ($X + Y + \text{Free Storage} = S \ge Z$), deleting both will always satisfy the condition.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case, as we only perform basic arithmetic and comparison operations.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input values.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total storage = S
 * Occupied storage = X + Y
 * Free storage = S - (X + Y)
 * Required storage = Z
 * 
 * Logic:
 * 1. If Free storage >= Z, we need to delete 0 apps.
 * 2. If Free storage < Z, we check if deleting one app (the larger one) is enough:
 *    (Free storage + max(X, Y)) >= Z. If yes, delete 1.
 * 3. If still not enough, we must delete both apps.
 */

void solve() {
    long long S, X, Y, Z;
    if (!(cin >> S >> X >> Y >> Z)) return;

    long long free_storage = S - (X + Y);

    if (free_storage >= Z) {
        cout << 0 << "\n";
    } else if (free_storage + max(X, Y) >= Z) {
        cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
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