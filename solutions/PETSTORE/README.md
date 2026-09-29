# [Pet Store (PETSTORE)](https://www.codechef.com/problems/PETSTORE)

- **Difficulty Rating**: 1126
- **Solved in**: 1 attempt(s)

## Problem Summary
Alice and Bob visit a pet store that has $N$ animals, each belonging to a specific type. They want to divide all the animals between themselves such that both Alice and Bob end up with the exact same multiset of animals (i.e., they have the same number of animals of each type). We need to determine if such a distribution is possible.

## Intuition & Mathematical Observation
For Alice and Bob to have the exact same multiset of animals, the total number of animals of any given type $T$ must be shared equally between them. 

1. If there are $K$ animals of type $T$, Alice must receive $K/2$ and Bob must receive $K/2$.
2. For $K/2$ to be an integer, $K$ must be an **even number**.
3. If any animal type appears an odd number of times in the store, it is mathematically impossible to split that specific type equally between two people.
4. Conversely, if every animal type appears an even number of times, we can simply give half of each type to Alice and the other half to Bob, which guarantees they both have identical multisets.

Therefore, the condition for "YES" is simply that the frequency of every distinct animal type in the input must be even.

## Complexity Analysis
- **Time Complexity**: $O(N \log K)$ or $O(N)$, where $N$ is the number of animals. Using a `std::map` results in $O(N \log K)$ (where $K$ is the number of unique types), while a frequency array would result in $O(N)$. Given the constraints (types up to 100), both are highly efficient.
- **Space Complexity**: $O(K)$, where $K$ is the number of unique animal types, used to store the frequency counts.

## Solution Code

```cpp
#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob must end up with the exact same multiset of animals.
 * This means the total count of each animal type in the store must be divisible by 2.
 * If any animal type appears an odd number of times, it is impossible to split them
 * equally between Alice and Bob.
 */

void solve() {
    int n;
    cin >> n;
    
    // Since animal types are between 1 and 100, we can use a map to count frequencies.
    map<int, int> counts;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        counts[type]++;
    }
    
    // Check if every animal type has an even count.
    bool possible = true;
    for (auto const& [type, count] : counts) {
        if (count % 2 != 0) {
            possible = false;
            break;
        }
    }
    
    if (possible) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
```