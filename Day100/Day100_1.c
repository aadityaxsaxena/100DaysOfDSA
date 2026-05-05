/*Problem: For each element, count how many smaller elements appear on right side.
Use merge sort technique or Fenwick Tree (BIT).*/

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int val;
    int index;
} Pair;
void merge(Pair* arr, int* count, int left, int mid, int right, Pair* temp) {
    int i = left;
    int j = mid + 1;
    int k = left;
    int rightCount = 0;
    while (i <= mid && j <= right) {
        if (arr[i].val <= arr[j].val) {
            count[arr[i].index] += rightCount;
            temp[k++] = arr[i++];
        } else {
            rightCount++;
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        count[arr[i].index] += rightCount;
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}
void mergeSort(Pair* arr, int* count, int left, int right, Pair* temp) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    mergeSort(arr, count, left, mid, temp);
    mergeSort(arr, count, mid + 1, right, temp);
    merge(arr, count, left, mid, right, temp);
}
int* countSmaller(int* nums, int n) {
    Pair* arr = (Pair*)malloc(n * sizeof(Pair));
    Pair* temp = (Pair*)malloc(n * sizeof(Pair));
    int* count = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }
    mergeSort(arr, count, 0, n - 1, temp);
    free(arr);
    free(temp);
    return count;
}
int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int* res = countSmaller(nums, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", res[i]);
    }
    free(res);
    return 0;
}