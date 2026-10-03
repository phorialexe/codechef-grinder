#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We need to buy X fruits in total, using at least two different kinds of fruits.
 * Let the prices be A, B, and C.
 * To minimize the cost, we should sort the prices such that p1 <= p2 <= p3.
 * 
 * To satisfy the condition of having at least two different kinds:
 * We must pick at least one fruit of some type and the rest of the fruits 
 * can be of the cheapest type available.
 * 
 * Strategy:
 * 1. Sort the prices: p1 <= p2 <= p3.
 * 2. We need to buy X fruits.
 * 3. To minimize cost, we should buy as many as possible of the cheapest fruit (p1).
 * 4. Since we need at least two types, we must buy at least one fruit of a different type.
 *    The cheapest way to satisfy this is to buy (X-1) fruits of price p1 and 1 fruit of price p2.
 *    Total cost = (X - 1) * p1 + p2.
 * 
 * Complexity:
 * Time: O(T) per test case, O(1) logic.
 * Space: O(1).
 */

void solve() {
    long long X, A, B, C;
    if (!(cin >> X >> A >> B >> C)) return;
    
    vector<long long> p = {A, B, C};
    sort(p.begin(), p.end());
    
    // We need X fruits total.
    // To minimize cost, we take (X-1) of the cheapest (p[0])
    // and 1 of the second cheapest (p[1]).
    // This satisfies the "at least 2 different kinds" condition.
    long long ans = (X - 1) * p[0] + p[1];
    
    cout << ans << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        solve();
    }
    return 0;
}