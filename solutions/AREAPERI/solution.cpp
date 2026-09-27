#include <bits/stdc++.h>
using namespace std;

/**
 * Problem: Area OR Perimeter
 * Logic:
 * Area = L * B
 * Perimeter = 2 * (L + B)
 * Compare the two values and output accordingly.
 * Constraints: 1 <= L, B <= 1000. 
 * Max Area = 1,000,000. Max Perimeter = 4,000.
 * Standard 'int' is sufficient, but 'long long' is used for safety.
 */

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long L, B;
    if (!(cin >> L >> B)) return 0;

    long long area = L * B;
    long long peri = 2 * (L + B);

    if (area > peri) {
        cout << "Area" << "\n";
        cout << area << "\n";
    } else if (peri > area) {
        cout << "Peri" << "\n";
        cout << peri << "\n";
    } else {
        // If equal, print "Eq" and the value
        cout << "Eq" << "\n";
        cout << area << "\n";
    }

    return 0;
}