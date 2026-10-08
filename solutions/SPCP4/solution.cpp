#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total students = N
 * Boys = X
 * Girls = N - X
 * Group size = K
 * 
 * Boys form groups: X / K groups, remainder boys = X % K
 * Girls form groups: (N - X) / K groups, remainder girls = (N - X) % K
 * 
 * Let remB = X % K
 * Let remG = (N - X) % K
 * 
 * Dancing requires one boy and one girl.
 * The number of pairs that can be formed is min(remB, remG).
 * The number of students left over (who must read) is:
 * Total remaining = remB + remG
 * Students dancing = 2 * min(remB, remG)
 * Students reading = (remB + remG) - 2 * min(remB, remG)
 * 
 * This simplifies to the absolute difference: |remB - remG|
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        long long n, x, k;
        cin >> n >> x >> k;

        long long boys = x;
        long long girls = n - x;

        long long remB = boys % k;
        long long remG = girls % k;

        // The number of students reading is the absolute difference 
        // between the remaining boys and remaining girls.
        long long reading = abs(remB - remG);

        cout << reading << "\n";
    }

    return 0;
}