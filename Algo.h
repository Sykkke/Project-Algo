#ifndef ALGO_H
#define ALGO_H

namespace Algo {
    // Numerical Methods: 
    //     1. Search
    //          a. Binary Search
    //          b. Ternary Search
    //          c. Newton's method for finding roots
    //     2. Integration
    //          a. Integration by Simpson's formula

    // a. Binary search function for a sorted array
    int binarySearch(const int* arr, int size, int target) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid; // Element found, return its index
            } else if (arr[mid] < target) {
                left = mid + 1; // Adjust the left boundary
            } else {
                right = mid - 1; // Adjust the right boundary
            }
        }

        return -1; // Element not found
    }
}

#endif // ALGO_H
