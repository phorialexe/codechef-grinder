#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We are given N people at positions X_1, X_2, ..., X_N.
 * The virus spreads if the distance between two people is <= 2.
 * This is a transitive property: if A infects B, and B infects C, then A infects C.
 * For each person i, we can simulate the spread by checking adjacent people.
 * Since N is very small (up to 8), we can simply iterate through each person
 * as the initial source of infection and calculate the size of the connected component
 * they belong to.
 */

void solve() {
    int N;
    cin >> N;
    vector<int> X(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
    }

    int min_infected = N;
    int max_infected = 1;

    // Try each person as the initial infected person
    for (int i = 0; i < N; ++i) {
        int current_infected = 1;
        
        // Look to the right
        int temp = i;
        while (temp + 1 < N && X[temp + 1] - X[temp] <= 2) {
            current_infected++;
            temp++;
        }
        
        // Look to the left
        temp = i;
        while (temp - 1 >= 0 && X[temp] - X[temp - 1] <= 2) {
            current_infected++;
            temp--;
        }
        
        if (current_infected < min_infected) {
            min_infected = current_infected;
        }
        if (current_infected > max_infected) {
            max_infected = current_infected;
        }
    }

    cout << min_infected << " " << max_infected << "\n";
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    if (!(cin >> T)) return 0;
    while (T--) {
        solve();
    }
    return 0;
}