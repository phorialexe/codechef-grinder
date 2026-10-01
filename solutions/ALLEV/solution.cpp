#include <bits/stdc++.h>
using namespace std;

/**
 * Problem Analysis:
 * We have an array A of size N. We can repeatedly add the last element to the 
 * second-to-last element and remove the last element.
 * 
 * Let the array be A_1, A_2, ..., A_N.
 * The operation: A_{N-1} = A_{N-1} + A_N, then remove A_N.
 * This means we can reduce the array to any size k (where 1 <= k < N) 
 * by keeping the first k-1 elements as they are, and the k-th element 
 * becomes the sum of the original A_k, A_{k+1}, ..., A_N.
 * 
 * We want to know if there exists a k such that all elements in the resulting 
 * array [A_1, A_2, ..., A_{k-1}, (A_k + ... + A_N)] are even.
 * 
 * This is possible if:
 * 1. For all i < k, A_i is even.
 * 2. The sum (A_k + A_{k+1} + ... + A_N) is even.
 * 
 * We can iterate through all possible values of k from 1 to N and check this condition.
 */

void solve() {
    int N;
    cin >> N;
    vector<long long> A(N);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    bool possible = false;

    // Try every possible final array size k (from 1 to N)
    for (int k = 1; k <= N; ++k) {
        bool current_k_possible = true;
        
        // Check if all elements before the last one are even
        for (int i = 0; i < k - 1; ++i) {
            if (A[i] % 2 != 0) {
                current_k_possible = false;
                break;
            }
        }
        
        if (!current_k_possible) continue;
        
        // Check if the sum of the remaining suffix is even
        long long suffix_sum = 0;
        for (int i = k - 1; i < N; ++i) {
            suffix_sum += A[i];
        }
        
        if (suffix_sum % 2 == 0) {
            possible = true;
            break;
        }
    }

    if (possible) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}