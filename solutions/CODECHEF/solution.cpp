#include <iostream>

using namespace std;

/**
 * Problem: CODECHEF
 * Logic: The problem states that Codechef rounds are held on Wednesday, 
 * which is the 4th day of the week (Sunday=1, Monday=2, Tuesday=3, Wednesday=4).
 * We need to output "YES" if N == 4, and "NO" otherwise.
 * 
 * Time Complexity: O(1)
 * Space Complexity: O(1)
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        if (n == 4) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}