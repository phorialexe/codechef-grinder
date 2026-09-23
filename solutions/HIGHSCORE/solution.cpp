#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef knows the total count of answers for each option (A, B, C, D).
 * He wants to maximize the marks he can *guarantee*.
 * 
 * If Chef decides to mark all N problems with a specific option (e.g., option A),
 * he is guaranteed to get exactly N_A marks, because there are exactly N_A 
 * problems where the answer is A.
 * 
 * To maximize the guaranteed marks, Chef should choose the option that appears 
 * the most frequently in the answer key. By marking all problems with the 
 * option that has the highest count among N_A, N_B, N_C, and N_D, he ensures 
 * that he gets at least that many marks.
 * 
 * Therefore, the answer is simply max(N_A, N_B, N_C, N_D).
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
        
        int na, nb, nc, nd;
        cin >> na >> nb >> nc >> nd;
        
        // The maximum marks guaranteed is the maximum of the counts of each option.
        int max_marks = max({na, nb, nc, nd});
        
        cout << max_marks << "\n";
    }

    return 0;
}