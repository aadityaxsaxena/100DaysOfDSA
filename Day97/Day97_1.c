/*Problem: Given meeting intervals, find minimum number of rooms required.
Sort by start time and use min-heap on end times.*/

#include <stdio.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    int (*intervalA)[2] = (int (*)[2])a;
    int (*intervalB)[2] = (int (*)[2])b;
    return intervalA[0][0] - intervalB[0][0];
}
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heapifyUp(int* heap, int i) {
    while (i > 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void heapifyDown(int* heap, int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < size && heap[left] < heap[smallest])
        smallest = left;
    if (right < size && heap[right] < heap[smallest])
        smallest = right;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(heap, size, smallest);
    }
}
int minMeetingRooms(int intervals[][2], int n) {
    if (n == 0) return 0;
    qsort(intervals, n, sizeof(intervals[0]), compare);
    int* heap = (int*)malloc(n * sizeof(int));
    int size = 0;
    heap[size++] = intervals[0][1];
    for (int i = 1; i < n; i++) {
        if (heap[0] <= intervals[i][0]) {
            heap[0] = intervals[i][1];
            heapifyDown(heap, size, 0);
        } else {
            heap[size++] = intervals[i][1];
            heapifyUp(heap, size - 1);
        }
    }
    int result = size;
    free(heap);
    return result;
}
int main() {
    int intervals[][2] = {
        {0, 30},
        {5, 10},
        {15, 20}
    };
    int n = sizeof(intervals) / sizeof(intervals[0]);
    printf("Minimum meeting rooms required = %d\n",
           minMeetingRooms(intervals, n));
    return 0;
}