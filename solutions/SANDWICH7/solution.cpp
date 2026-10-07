#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs 2 pieces of bread for every sandwich.
 * Chef can use either ham or cheese for the filling.
 * 
 * Let S be the number of sandwiches.
 * Constraint 1: 2 * S <= B  => S <= B / 2
 * Constraint 2: S <= H + C (Total fillings available)
 * 
 * Therefore, the maximum number of sandwiches is min(B / 2, H + C).
 */

void solve() {
    long long B, H, C;
    if (!(cin >> B >> H >> C)) return;
    
    long long max_sandwiches_by_bread = B / 2;
    long long max_sandwiches_by_filling = H + C;
    
    long long result = min(max_sandwiches_by_bread, max_sandwiches_by_filling);
    
    cout << result << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // The problem description implies a single test case based on the format,
    // but standard competitive programming practice often involves a test case count.
    // Given the constraints and description, we handle the input as provided.
    solve();
    
    return 0;
}