#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Alice and Bob must end up with the exact same multiset of animals.
 * This means the total count of each animal type in the store must be divisible by 2.
 * If any animal type appears an odd number of times, it is impossible to split them
 * equally between Alice and Bob, because one person would end up with more of that
 * specific type than the other.
 * 
 * If all animal types appear an even number of times, we can simply give half of
 * each type to Alice and the other half to Bob, satisfying the condition.
 * 
 * Time Complexity: O(N) per test case, where N is the number of animals.
 * Space Complexity: O(K) where K is the range of animal types (100).
 */

void solve() {
    int n;
    cin >> n;
    
    // Since animal types are between 1 and 100, we can use a frequency array.
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