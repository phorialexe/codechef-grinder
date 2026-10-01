#include <iostream>
#include <vector>
#include <string>

using namespace std;

/**
 * Problem Analysis:
 * Chef starts at North.
 * 0 seconds: North
 * 1 second: East
 * 2 seconds: South
 * 3 seconds: West
 * 4 seconds: North (cycle repeats every 4 seconds)
 * 
 * The direction is determined by X % 4.
 */

void solve() {
    int x;
    if (!(cin >> x)) return;
    
    int direction = x % 4;
    
    // Mapping the remainder to the corresponding direction
    if (direction == 0) {
        cout << "North" << "\n";
    } else if (direction == 1) {
        cout << "East" << "\n";
    } else if (direction == 2) {
        cout << "South" << "\n";
    } else {
        cout << "West" << "\n";
    }
}

int main() {
    // Optimize I/O operations for faster execution
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    
    return 0;
}