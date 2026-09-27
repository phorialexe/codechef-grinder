#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N types of colors, with A_i balls of color i.
 * We need to place these balls into boxes such that no box contains two balls of the same color.
 * 
 * If we have A_i balls of a specific color, we must have at least A_i boxes 
 * to ensure that no two balls of that color share a box.
 * 
 * Since this constraint must hold for every color i (1 <= i <= N), 
 * the minimum number of boxes required must be at least max(A_1, A_2, ..., A_N).
 * 
 * If we have max(A_1, ..., A_N) boxes, we can always distribute the balls 
 * such that no box contains two balls of the same color by using a cyclic 
 * distribution strategy. Thus, the answer is simply the maximum value in the array A.
 * 
 * Time Complexity: O(N) per test case.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        int n;
        cin >> n;
        
        long long max_balls = 0;
        for (int i = 0; i < n; ++i) {
            long long a;
            cin >> a;
            if (a > max_balls) {
                max_balls = a;
            }
        }
        
        cout << max_balls << "\n";
    }

    return 0;
}