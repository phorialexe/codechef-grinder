#include <iostream>

/**
 * Problem: NEIREM
 * The city has 100 neighborhoods in total.
 * Given N (number of visited neighborhoods), we need to find (100 - N).
 * Constraints: 0 <= N <= 100.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    // Read the single integer N as specified in the input format.
    if (std::cin >> n) {
        int remaining = 100 - n;
        std::cout << remaining << std::endl;
    }

    return 0;
}