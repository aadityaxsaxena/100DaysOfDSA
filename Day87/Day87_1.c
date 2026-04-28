/*Problem: Implement Binary Search Iterative - Implement the algorithm.
Input:
- First line: integer n
- Second line: n space-separated integers
Output:
- Print the sorted array or search result
Example:
Input:
5
64 34 25 12 22
Output:
12 22 25 34 64*/

#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    int n, i, key;
    scanf("%d", &n);
    int arr[n];
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, n, sizeof(int), compare);
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    scanf("%d", &key);
    int result = binarySearch(arr, n, key);
    if(result != -1)
        printf("\nElement found at index %d", result);
    else
        printf("\nElement not found");
    return 0;
}