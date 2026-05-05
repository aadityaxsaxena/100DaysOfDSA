/*Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
Example 1:
Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.
Example 2:
Input: nums = [-1]
Output: [0]
Example 3:
Input: nums = [-1,-1]
Output: [0,0]
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int val;
    int idx;
} Node;
void merge(Node* arr, int* res, Node* temp, int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;
    while (i <= mid && j <= right) {
        if (arr[j].val < arr[i].val) {
            rightCount++;
            temp[k++] = arr[j++];
        } else {
            res[arr[i].idx] += rightCount;
            temp[k++] = arr[i++];
        }
    }
    while (i <= mid) {
        res[arr[i].idx] += rightCount;
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}
void mergeSort(Node* arr, int* res, Node* temp, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, res, temp, left, mid);
    mergeSort(arr, res, temp, mid + 1, right);
    merge(arr, res, temp, left, mid, right);
}
int* countSmaller(int* nums, int numsSize, int* returnSize) {
    Node* arr = (Node*)malloc(numsSize * sizeof(Node));
    Node* temp = (Node*)malloc(numsSize * sizeof(Node));
    int* res = (int*)calloc(numsSize, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].idx = i;
    }
    mergeSort(arr, res, temp, 0, numsSize - 1);
    *returnSize = numsSize;
    free(arr);
    free(temp);
    return res;
}