/*Problem Statement
Given an array of integers containing both positive and negative values, find the length of the longest contiguous subarray whose sum is equal to zero.
Input Format
An integer array arr[].
Output Format
Print the length of the longest subarray with sum equal to zero.
Sample Input
15 -2 2 -8 1 7 10 23
Sample Output
5
Explanation
The subarray [-2, 2, -8, 1, 7] has a sum of 0 and is the longest such subarray.*/

#include <stdio.h>
#define MAX 1000
int maxLen(int arr[], int n) {
    int sum = 0, max_length = 0;
    int hash[2 * MAX + 1];
    for (int i = 0; i < 2 * MAX + 1; i++) {
        hash[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0) {
            max_length = i + 1;
        }
        if (hash[sum + MAX] != -1) {
            int length = i - hash[sum + MAX];
            if (length > max_length) {
                max_length = length;
            }
        } else {
            hash[sum + MAX] = i;
        }
    }
    return max_length;
}
int main() {
    int n, arr[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int result = maxLen(arr, n);
    printf("%d\n", result);
    return 0;
}