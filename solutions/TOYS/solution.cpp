#include <iostream>
#include <algorithm>

/**
 * Problem Analysis:
 * Chef starts with N toys.
 * Each day, if he has at least one toy, he plays with one and breaks it.
 * This means he loses 1 toy per day, provided he has toys available.
 * 
 * After M days:
 * - If M >= N, he will break all N toys and be left with 0.
 * - If M < N, he will break M toys and be left with N - M.
 * 
 * The logic is simply: max(0, N - M).
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    // The problem description implies a single test case per input, 
    // but standard competitive programming practice often handles 
    // multiple test cases if specified. Given the input format:
    if (std::cin >> n >> m) {
        if (m >= n) {
            std::cout << 0 << std::endl;
        } else {
            std::cout << (n - m) << std::endl;
        }
    }
    
    return 0;
}