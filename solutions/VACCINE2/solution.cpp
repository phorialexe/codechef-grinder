#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have N people with ages a_i.
 * A person is "at risk" if age >= 80 or age <= 9.
 * We can vaccinate at most D people per day.
 * Constraint: We cannot vaccinate both "at risk" and "not at risk" people on the same day.
 * 
 * Strategy:
 * 1. Count the number of "at risk" people (risk_count) and "not at risk" people (safe_count).
 * 2. Since we cannot mix them, we calculate the days required for each group independently.
 * 3. For a group of size S, the number of days required is ceil(S / D).
 *    Using integer arithmetic, this is (S + D - 1) / D.
 * 4. Total days = days_for_risk + days_for_safe.
 */

void solve() {
    int N, D;
    cin >> N >> D;
    
    int risk_count = 0;
    int safe_count = 0;
    
    for (int i = 0; i < N; ++i) {
        int age;
        cin >> age;
        if (age >= 80 || age <= 9) {
            risk_count++;
        } else {
            safe_count++;
        }
    }
    
    // Calculate days for each group using ceiling division
    // ceil(a/b) = (a + b - 1) / b for integers
    int days_risk = (risk_count + D - 1) / D;
    int days_safe = (safe_count + D - 1) / D;
    
    cout << (days_risk + days_safe) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    
    return 0;
}