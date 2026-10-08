# [Count of Maximum (MAXCOUNT)](https://www.codechef.com/problems/MAXCOUNT)

- **Difficulty Rating**: 1180
- **Solved in**: 2 attempt(s)

## Problem Summary
Given an array of $N$ integers, the task is to identify the element that appears most frequently. If there are multiple elements with the same maximum frequency, you must return the smallest among them. You are required to output both the element and its frequency.

## Intuition & Mathematical Observation
To solve this problem efficiently, we need to track the frequency of every unique number in the input array. 

1. **Frequency Mapping**: A `std::map<int, int>` is an ideal data structure here. It maps each unique number (key) to its count (value).
2. **Handling Ties**: The problem specifies that if two numbers have the same frequency, the smaller number should be chosen. Since `std::map` in C++ automatically stores keys in **ascending order**, iterating through the map sequentially allows us to process smaller numbers first.
3. **Selection Logic**: By maintaining a `maxCount` variable and updating our `bestElement` only when we encounter a frequency **strictly greater** than the current `maxCount`, we naturally preserve the smallest element in the event of a tie.

## Complexity Analysis
- **Time Complexity**: $O(N \log N)$, where $N$ is the number of elements in the array. Each insertion into the `std::map` takes $O(\log K)$ time (where $K$ is the number of unique elements), and we perform this for all $N$ elements.
- **Space Complexity**: $O(N)$, as we store at most $N$ unique elements in the map.

## Solution Code

```cpp
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
```