#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Chef buys the metal frame if Y <= 2 * X.
 * Otherwise, Chef buys the plastic frame.
 * 
 * Constraints:
 * 1 <= X, Y <= 2000
 * Since the values are small, standard 'int' is sufficient, 
 * but 'long long' is used for safety against potential overflow 
 * in larger variations of this problem.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // The problem description implies a single test case per run 
    // based on the input format description, but standard competitive 
    // programming practice often involves reading until EOF or a test case count.
    // Given the description "The first and only line of input will contain...",
    // we process the single line provided.
    
    long long X, Y;
    if (cin >> X >> Y) {
        // Condition: Metal if Y <= 2 * X
        if (Y <= 2 * X) {
            cout << "METAL" << "\n";
        } else {
            cout << "PLASTIC" << "\n";
        }
    }

    return 0;
}