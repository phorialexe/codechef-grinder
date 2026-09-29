#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * Problem Analysis:
 * Chef needs 2 popcorns and 3 drinks.
 * X = price of 1 popcorn, Y = price of 1 drink, Z = price of 1 combo (1 popcorn + 1 drink).
 * 
 * Possible strategies to get at least 2 popcorns and 3 drinks:
 * 1. Buy everything individually: 2*X + 3*Y
 * 2. Buy 1 combo, then 1 popcorn and 2 drinks: Z + X + 2*Y
 * 3. Buy 2 combos, then 1 drink: 2*Z + Y
 * 
 * Note: Buying 3 combos would result in 3 popcorns and 3 drinks. 
 * Since the problem asks for the minimum amount to get 2 popcorns and 3 drinks,
 * and prices are positive, 2*Z + Y is always cheaper than 3*Z (because Y < Z).
 */

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long X, Y, Z;
    if (!(cin >> X >> Y >> Z)) return 0;

    // Strategy 1: All individual
    long long option1 = 2 * X + 3 * Y;
    
    // Strategy 2: 1 combo + 1 popcorn + 2 drinks
    long long option2 = Z + X + 2 * Y;
    
    // Strategy 3: 2 combos + 1 drink
    long long option3 = 2 * Z + Y;

    // The minimum of these strategies is the answer
    long long ans = min({option1, option2, option3});
    
    cout << ans << endl;

    return 0;
}