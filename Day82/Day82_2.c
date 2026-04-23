/*Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
You must write an algorithm with O(log n) runtime complexity.
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
*/

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    int ans = numsSize;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}