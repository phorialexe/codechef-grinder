#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have three colors with counts A, B, and C. We need to arrange them in a line
 * such that no two adjacent strips have the same color.
 * 
 * Let the counts be sorted such that x <= y <= z.
 * The most restrictive condition is the color with the maximum count (z).
 * If we place the z strips of the most frequent color, we have z-1 gaps between them.
 * We can place the other (x + y) strips into these gaps.
 * To ensure no two strips of the most frequent color are adjacent, we need at least
 * (z - 1) strips of other colors to fill the gaps.
 * 
 * Thus, the condition for a valid arrangement is:
 * (x + y) >= (z - 1)
 * 
 * This is equivalent to:
 * x + y + 1 >= z
 * 
 * Since the constraints are small (up to 10), this logic holds perfectly.
 */

void solve() {
    long long arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    
    // Sort the counts to easily identify the maximum
    sort(arr, arr + 3);
    
    // arr[0] is smallest, arr[1] is middle, arr[2] is largest
    // Condition: sum of two smaller must be at least (largest - 1)
    if (arr[0] + arr[1] >= arr[2] - 1) {
        cout << "YES" << "\n";
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}