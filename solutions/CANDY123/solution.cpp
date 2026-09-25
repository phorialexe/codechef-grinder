#include <iostream>

using namespace std;

/**
 * Problem Analysis:
 * Limak eats 1, 3, 5, ... candies.
 * Bob eats 2, 4, 6, ... candies.
 * Limak loses if his current turn requirement > remaining A.
 * Bob loses if his current turn requirement > remaining B.
 * 
 * Constraints: A, B <= 1000.
 * A simple simulation will run in O(sqrt(max(A, B))) per test case, 
 * which is well within the time limits for T=1000.
 */

void solve() {
    int A, B;
    cin >> A >> B;
    
    int limak_eaten = 0;
    int bob_eaten = 0;
    int turn = 1;
    
    while (true) {
        // Limak's turn
        if (limak_eaten + turn <= A) {
            limak_eaten += turn;
            turn++;
        } else {
            cout << "Bob" << endl;
            return;
        }
        
        // Bob's turn
        if (bob_eaten + turn <= B) {
            bob_eaten += turn;
            turn++;
        } else {
            cout << "Limak" << endl;
            return;
        }
    }
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    
    while (t--) {
        solve();
    }
    
    return 0;
}