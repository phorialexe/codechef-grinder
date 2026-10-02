#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Distance to travel: N
 * Petrol: Price X, Mileage A km/litre.
 * Cost for petrol = (N / A) * X
 * Diesel: Price Y, Mileage B km/litre.
 * Cost for diesel = (N / B) * Y
 * 
 * To avoid floating point precision issues, we compare:
 * (N * X) / A  vs  (N * Y) / B
 * Multiplying both sides by (A * B), we compare:
 * (N * X * B)  vs  (N * Y * A)
 * Since N > 0, we can divide by N:
 * (X * B)  vs  (Y * A)
 * 
 * Using long long to prevent any potential overflow, although constraints 
 * (up to 100) are small enough for standard int.
 */

void solve() {
    long long N, X, Y, A, B;
    cin >> N >> X >> Y >> A >> B;

    // Cost of petrol = (N * X) / A
    // Cost of diesel = (N * Y) / B
    // Compare (N * X) / A and (N * Y) / B
    // Equivalent to comparing (N * X * B) and (N * Y * A)
    
    long long petrol_cost_scaled = N * X * B;
    long long diesel_cost_scaled = N * Y * A;

    if (petrol_cost_scaled < diesel_cost_scaled) {
        cout << "PETROL" << "\n";
    } else if (diesel_cost_scaled < petrol_cost_scaled) {
        cout << "DIESEL" << "\n";
    } else {
        cout << "ANY" << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}