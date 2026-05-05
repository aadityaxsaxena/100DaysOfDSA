/*Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?
Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4
*/

#include <stdlib.h>
int partition(int* nums, int low, int high) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(nums, low, pivotIndex);
    int pivot = nums[low];
    int j = low;
    for (int i = low + 1; i <= high; i++) {
        if (nums[i] < pivot) {
            j++;
            swap(nums, i, j);
        }
    }
    swap(nums, low, j);
    return j;
}