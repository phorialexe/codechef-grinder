#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Body Mass Index
 * BMI = M / H^2
 * Constraints: 1 <= M <= 10^4, 1 <= H <= 10^2
 * Since H^2 divides M, BMI will always be an integer.
 * 
 * Categories:
 * 1: BMI <= 18
 * 2: 19 <= BMI <= 24
 * 3: 25 <= BMI <= 29
 * 4: BMI >= 30
 */

int main() {
    // Fast I/O for competitive programming
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long m, h;
        cin >> m >> h;
        
        // Calculate BMI. Since H^2 divides M, integer division is safe.
        long long bmi = m / (h * h);
        
        if (bmi <= 18) {
            cout << 1 << "\n";
        } else if (bmi >= 19 && bmi <= 24) {
            cout << 2 << "\n";
        } else if (bmi >= 25 && bmi <= 29) {
            cout << 3 << "\n";
        } else {
            // bmi >= 30
            cout << 4 << "\n";
        }
    }
    
    return 0;
}