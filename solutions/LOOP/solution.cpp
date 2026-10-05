#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

/**
 * Problem Analysis:
 * On a circular track of length M, there are two paths between any two points A and B.
 * Path 1: Direct distance = abs(A - B)
 * Path 2: The "other way" around = M - abs(A - B)
 * The minimum distance is the minimum of these two values.
 * 
 * Constraints:
 * M <= 10^9, so we should use long long to prevent any potential overflow,
 * though int is sufficient for the subtraction result.
 */

void solve() {
    long long A, B, M;
    if (!(cin >> A >> B >> M)) return;
    
    long long diff = abs(A - B);
    long long min_dist = min(diff, M - diff);
    
    cout << min_dist << "\n";
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