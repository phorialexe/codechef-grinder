#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * Total bill = N
 * Number of people = K + 1 (You + K friends)
 * Fair share per person = N / (K + 1)
 * Each of the K friends pays floor(N / (K + 1))
 * Total amount received from friends = K * floor(N / (K + 1))
 * Net amount you paid = Total bill - Total amount received
 * Net amount = N - (K * floor(N / (K + 1)))
 * 
 * Constraints:
 * N <= 1000, K <= 10.
 * Using long long is safe, though int is sufficient here.
 */

int main() {
    // Fast I/O setup
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        long long n, k;
        cin >> n >> k;

        // The total number of people is K friends + yourself = K + 1
        long long total_people = k + 1;
        
        // Each friend pays floor(N / (K + 1))
        long long share_per_person = n / total_people;
        
        // Total amount paid back by K friends
        long long total_repaid = k * share_per_person;
        
        // Net amount you paid
        long long net_payment = n - total_repaid;
        
        cout << net_payment << "\n";
    }

    return 0;
}