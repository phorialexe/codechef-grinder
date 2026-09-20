#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Self Defence Training
 * The condition for eligibility is age A such that 10 <= A <= 60.
 * We iterate through the list of ages for each test case and count how many
 * satisfy this condition.
 * 
 * Time Complexity: O(T * N), where T is the number of test cases and N is the number of women.
 * Space Complexity: O(1) auxiliary space (excluding input storage).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int n;
        cin >> n;
        
        int eligible_count = 0;
        for (int i = 0; i < n; ++i) {
            int age;
            cin >> age;
            // Check if age is within the inclusive range [10, 60]
            if (age >= 10 && age <= 60) {
                eligible_count++;
            }
        }
        
        cout << eligible_count << "\n";
    }
    
    return 0;
}