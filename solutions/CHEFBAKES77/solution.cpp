#include <iostream>

/**
 * Problem Analysis:
 * Total weight of cakes = N * X.
 * Each vehicle capacity = Y.
 * The number of cakes that can fit in one vehicle is floor(Y / X).
 * Let k = floor(Y / X) be the number of cakes per vehicle.
 * The number of vehicles required is ceil(N / k).
 * Using integer arithmetic, ceil(N / k) can be calculated as (N + k - 1) / k.
 */

int main() {
    // Optimize I/O operations
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    long long N, X, Y;
    
    // The problem specifies a single line containing N, X, and Y.
    if (std::cin >> N >> X >> Y) {
        // Number of cakes per vehicle
        long long cakes_per_vehicle = Y / X;

        // Number of vehicles needed = ceil(N / cakes_per_vehicle)
        // Using integer division: (N + cakes_per_vehicle - 1) / cakes_per_vehicle
        long long vehicles_needed = (N + cakes_per_vehicle - 1) / cakes_per_vehicle;

        std::cout << vehicles_needed << std::endl;
    }

    return 0;
}