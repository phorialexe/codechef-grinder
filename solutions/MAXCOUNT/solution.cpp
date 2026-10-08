#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

/**
 * Problem Analysis:
 * We need to find the element with the highest frequency.
 * In case of a tie, choose the smallest element.
 * 
 * Approach:
 * 1. Use a std::map<int, int> to store the frequency of each element.
 * 2. Since std::map stores keys in ascending order, we can iterate through 
 *    the map and update the result only when we find a frequency strictly 
 *    greater than the current maximum. This ensures that if two elements 
 *    have the same frequency, the smaller one (encountered first) is kept.
 * 
 * Complexity:
 * Time: O(N log N) per test case due to map insertions.
 * Space: O(N) to store the frequencies.
 */

std::pair<int, int> mostFrequent(int N, const std::vector<int>& A) {
    std::map<int, int> freq;
    for (int x : A) {
        freq[x]++;
    }

    int bestElement = -1;
    int maxCount = -1;

    // Iterating through the map (sorted by key)
    for (auto const& [val, count] : freq) {
        // Strict inequality ensures we keep the smallest element in case of a tie
        if (count > maxCount) {
            maxCount = count;
            bestElement = val;
        }
    }

    return {bestElement, maxCount};
}

// Note: The platform handles the main() function and input parsing.
// The code above provides the required logic function.