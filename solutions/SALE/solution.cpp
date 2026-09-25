#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef buys 3 items with prices A, B, and C.
 * The rule is: the item with the lowest price among the three is free.
 * The total amount to pay is (A + B + C) - min(A, B, C).
 * 
 * Constraints:
 * 1 <= T <= 100
 * 1 <= A, B, C <= 10
 * 
 * Since the values are small, standard integer types are sufficient.
 * Time Complexity: O(T) per test case, O(1) per calculation.
 * Space Complexity: O(1).
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        
        // Calculate the sum of all three items
        int total_sum = a + b + c;
        
        // Find the minimum price among the three
        int min_price = min({a, b, c});
        
        // The amount to pay is the total sum minus the cheapest item
        int amount_to_pay = total_sum - min_price;
        
        cout << amount_to_pay << "\n";
    }
    
    return 0;
}