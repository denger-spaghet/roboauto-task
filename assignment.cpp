#include <vector>
#include <cstdint>
#include <iostream>

#include <ranges>
#include <algorithm>

#include "INode.h"

/*
 * General rules:
 * - You can use modern C++ features (anything that is supported by modern compilers)
 * - Try to validate input parameters if it makes sense, throw exceptions if needed
 * - You are allowed to use STL (so adding includes is allowed)
 */

/**
 * Implement a method that returns number that is closest to zero in a given vector.
 * If there are two equally close to zero elements like 2 and -2,
 * then consider the positive element to be "closer" to zero.
 */
int getClosestToZero(const std::vector<int>& arr) {
    if (arr.empty()) throw std::invalid_argument("array is empty");
    /*auto closest = arr[0];
    
    for (auto n : arr) {
        if (abs(n) < abs(closest) ||
           (abs(n) == abs(closest) && n > closest)) {
            closest = n;
        }
    }
    return closest;*/

    //sort according to comp func, then pick smallest index
    return *std::ranges::min_element(arr, [](int a, int b) {
        return std::abs(a) < std::abs(b) || (std::abs(a) == std::abs(b) && a > b);
    });
}

/**
 * Please implement this method to return count of chunks in given array.
 *
 * Chunk is defined as continuous sequence of one or more non-zero numbers separated by one or more zeroes.
 * Input can contain leading and trailing zeroes.
 *
 * Example: [5, 4, 0, 0, -1, 0, 2, 0, 0] contains 3 chunks
 */
std::size_t countChunks(const std::vector<int>& arr) {
    if (arr.empty()) throw std::invalid_argument("array is empty");

    std::size_t cnt = 0;
    auto it = arr.begin();

    while(it != arr.end()) {
        it = std::ranges::find_if(it, arr.end(), [](int x) { return x != 0; }); 
        if(it == arr.end()) break;
        cnt ++;
        it = std::ranges::find(it, arr.end(), 0);
    }

    return cnt;
}

/**
 * Open INode.h to see the INode interface.
 *
 * Implement following function that shall traverse the tree,
 * and return the sum of the values (INode.value()) of all nodes
 * at the level 'n' in the tree.
 * 
 * Node root is assumed to be at the level 0. All its children are level 1, etc.
 */
int getLevelSum(const INode& root, std::size_t n) {
    return 0;
}

/**
 * Imagine a sort algorithm, that sorts array of integers by repeatedly reversing
 * the order of the first several elements of it.
 *
 * For example, to sort [12,13,11,14], you need to reverse the order of the first two (2)
 * elements. You will get [13,12,11,14].
 * Then you shall reverse the order of the first three (3) elements,
 * and you will get [11,12,13,14]
 *
 * For this assignment you shall implement function
 * that returns list of integers corresponding to the required reversals.
 * E.g. for given vector [12,13,11,14]
 * the function should return [2, 3].
 */
std::vector<std::size_t> getReversalsToSort(const std::vector<int>& arr) {
    std::vector<std::size_t> ret;
    return ret;
}

int main() {
    /*std::vector<int> getClosestIn = {-9,5,-1,8,6, 1};
    int val = getClosestToZero(getClosestIn);
    std::cout << val << std::endl;*/
    
    std::vector<int> getChunksIn = {5};
    std::size_t noChunks = countChunks(getChunksIn);
    std::cout << noChunks << std::endl;
    return 0;
}
