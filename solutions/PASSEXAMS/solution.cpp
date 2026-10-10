#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Passing Exams
 * Logic:
 * Chef needs to score >= 50 in at least 2 out of 3 exams.
 * We can count how many exams have a score >= 50.
 * If the count is >= 2, output "Yes", otherwise "No".
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        
        int count = 0;
        if (x >= 50) count++;
        if (y >= 50) count++;
        if (z >= 50) count++;
        
        if (count >= 2) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
    
    return 0;
}