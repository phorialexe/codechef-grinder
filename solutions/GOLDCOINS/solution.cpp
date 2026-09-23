#include <iostream>

using namespace std;

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int A, B, X, Y;
    // Read the input values
    if (!(cin >> A >> B >> X >> Y)) return 0;

    // Compare goals to determine if Chef wins or loses
    if (X > Y) {
        // Chef wins
        cout << A << endl;
    } else {
        // Chef loses
        cout << B << endl;
    }

    return 0;
}