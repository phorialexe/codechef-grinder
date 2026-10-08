# [Fair Share Settlement (FAIRSHARE)](https://www.codechef.com/problems/FAIRSHARE)

- **Difficulty Rating**: 665
- **Solved in**: 1 attempt(s)

## Problem Summary
You are dining with $K$ friends, making the total number of people $K + 1$. The total bill is $N$. Each of your $K$ friends contributes an equal amount, which is the floor of the total bill divided by the total number of people: $\lfloor N / (K + 1) \rfloor$. You are responsible for paying the remainder of the bill. The goal is to calculate the net amount you have to pay.

## Intuition & Mathematical Observation
1. **Total People**: Since there are $K$ friends and yourself, the total number of people sharing the bill is $K + 1$.
2. **Individual Share**: According to the problem, each friend pays $\lfloor N / (K + 1) \rfloor$.
3. **Total Repayment**: The $K$ friends collectively pay $K \times \lfloor N / (K + 1) \rfloor$.
4. **Your Payment**: Since you cover the rest of the bill, your payment is the total bill $N$ minus the amount paid by your friends:
   $$\text{Net Payment} = N - (K \times \lfloor N / (K + 1) \rfloor)$$

Given the constraints ($N \le 1000, K \le 10$), standard integer arithmetic is perfectly sufficient to handle these calculations without overflow.

## Complexity Analysis
- **Time Complexity**: $O(1)$ per test case. Since we perform a constant number of arithmetic operations, the total time complexity is $O(T)$, where $T$ is the number of test cases.
- **Space Complexity**: $O(1)$, as we only use a few variables to store the input and the result.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total bill = N
 * Number of people = K + 1 (You + K friends)
 * Fair share per person = N / (K + 1)
 * Each of the K friends pays floor(N / (K + 1))
 * Total amount received from friends = K * floor(N / (K + 1))
 * Net amount you paid = Total bill - Total amount received
 * Net amount = N - (K * floor(N / (K + 1)))
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // The total number of people is K friends + yourself = K + 1
        long long total_people = k + 1;
        
        // Each friend pays floor(N / (K + 1))
        long long share_per_person = n / total_people;
        
        // Total amount paid back by K friends
        long long total_repaid = k * share_per_person;
        
        // Net amount you paid
        long long net_payment = n - total_repaid;
        
        cout << net_payment << "\n";
    }

    return 0;
}
```