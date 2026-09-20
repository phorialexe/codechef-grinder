#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Each floor has 10 rooms.
 * Floor 1: 1-10
 * Floor 2: 11-20
 * ...
 * Floor i: 10*(i-1) + 1 to 10*i
 * 
 * To find the floor number for a room X:
 * Floor(X) = ceil(X / 10.0)
 * Using integer arithmetic, this is (X + 9) / 10.
 * 
 * The number of floors to travel is the absolute difference between the floor numbers.
 */

void solve() {
    int x, y;
    cin >> x >> y;
    
    // Calculate floor for room X
    int floorX = (x + 9) / 10;
    
    // Calculate floor for room Y
    int floorY = (y + 9) / 10;
    
    // The number of floors to travel is the absolute difference
    int result = abs(floorX - floorY);
    
    cout << result << "\n";
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