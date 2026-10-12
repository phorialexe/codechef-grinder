#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given two players A and B with three statistics: Runs (R), Wickets (W), and Catches (C).
 * We need to compare them in each category.
 * Let countA be the number of categories where player A has a higher value than player B.
 * Let countB be the number of categories where player B has a higher value than player A.
 * Since the problem guarantees that values are never equal in any category, 
 * countA + countB = 3.
 * If countA > countB, player A is better. Otherwise, player B is better.
 * 
 * Time Complexity: O(T) where T is the number of test cases.
 * Space Complexity: O(1) as we only use a few integer variables.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int r1, w1, c1;
        int r2, w2, c2;
        
        cin >> r1 >> w1 >> c1;
        cin >> r2 >> w2 >> c2;
        
        int countA = 0;
        int countB = 0;
        
        // Compare Runs
        if (r1 > r2) countA++;
        else countB++;
        
        // Compare Wickets
        if (w1 > w2) countA++;
        else countB++;
        
        // Compare Catches
        if (c1 > c2) countA++;
        else countB++;
        
        // Determine winner
        if (countA > countB) {
            cout << "A" << "\n";
        } else {
            cout << "B" << "\n";
        }
    }
    
    return 0;
}