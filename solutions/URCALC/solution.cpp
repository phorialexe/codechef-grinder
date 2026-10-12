#include <iostream>
#include <iomanip>

using namespace std;

/**
 * Problem: URCALC - Program Your Own CALCULATOR
 * The primary issue in the previous attempt was the lack of explicit 
 * floating-point formatting. Using fixed and setprecision ensures that 
 * division results meet the required 10^-6 precision tolerance.
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double a, b;
    char c;

    // Reading inputs
    if (!(cin >> a >> b >> c)) return 0;

    // Set precision to ensure floating point results are accurate
    cout << fixed << setprecision(6);

    // Perform operation based on the operator C
    if (c == '+') {
        cout << (a + b) << endl;
    } else if (c == '-') {
        cout << (a - b) << endl;
    } else if (c == '*') {
        cout << (a * b) << endl;
    } else if (c == '/') {
        // Division requires floating point result
        cout << (a / b) << endl;
    }

    return 0;
}