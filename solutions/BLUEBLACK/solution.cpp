#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef needs either:
 * 1. 3 blue pens: Cost = 3 * A
 * 2. 1 blue pen and 1 black pen: Cost = A + B
 * 
 * We need to find the minimum of (3 * A) and (A + B).
 * Constraints: 10 <= A, B <= 50.
 * Since the values are small, standard integer types are sufficient, 
 * but we use long long for safety as per best practices.
 */

void solve() {
    long long A, B;
    if (!(cin >> A >> B)) return;

    long long option1 = 3 * A;
    long long option2 = A + B;

    cout << min(option1, option2) << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description does not explicitly state multiple test cases,
    // but the instructions mention "Handle multiple test cases (e.g. int t; cin >> t; while(t--))".
    // Checking if there is a test case count provided.
    // Based on the standard format for such problems, we check if input exists.
    
    int t = 1; 
    // If the problem implies a test case count, uncomment the following:
    // cin >> t;
    
    while (t--) {
        solve();
    }

    return 0;
}