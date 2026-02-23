/*Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]*/

void flip(int* array, int startIndex, int endIndex) {
    while (startIndex < endIndex) {
        int swapTemp = array[startIndex];
        array[startIndex] = array[endIndex];
        array[endIndex] = swapTemp;
        startIndex++;
        endIndex--;
    }
}

void rotate(int* values, int length, int shift) {
    if (length <= 1) return;
    shift = shift % length;
    if (shift == 0) return;
    flip(values, 0, length - 1);
    flip(values, 0, shift - 1);
    flip(values, shift, length - 1);
}