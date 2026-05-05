/*Problem: Given intervals, merge all overlapping ones.
Sort first, then compare with previous.*/

#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    int (*i1)[2] = (int (*)[2])a;
    int (*i2)[2] = (int (*)[2])b;
    return i1[0][0] - i2[0][0];
}
int main() {
    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);
    int intervals[n][2];
    printf("Enter intervals (start end):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }
    qsort(intervals, n, sizeof(intervals[0]), compare);
    int result[n][2];
    int idx = 0;
    result[0][0] = intervals[0][0];
    result[0][1] = intervals[0][1];
    for (int i = 1; i < n; i++) {
        if (intervals[i][0] <= result[idx][1]) {
            if (intervals[i][1] > result[idx][1]) {
                result[idx][1] = intervals[i][1];
            }
        } else {
            idx++;
            result[idx][0] = intervals[i][0];
            result[idx][1] = intervals[i][1];
        }
    }
    printf("\nMerged Intervals:\n");
    for (int i = 0; i <= idx; i++) {
        printf("[%d, %d]\n", result[i][0], result[i][1]);
    }
    return 0;
}