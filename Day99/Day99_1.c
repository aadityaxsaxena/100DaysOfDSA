/*Problem: Given a target distance and cars’ positions & speeds, compute the number of car fleets reaching the destination.
Sort cars by position in descending order and calculate time to reach target.*/

#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int pos;
    int speed;
} Car;
int compare(const void* a, const void* b) {
    Car* c1 = (Car*)a;
    Car* c2 = (Car*)b;
    if (c2->pos > c1->pos) return 1;
    if (c2->pos < c1->pos) return -1;
    return 0;
}
int carFleet(int target,
             int* position,
             int positionSize,
             int* speed,
             int speedSize) {
    Car* cars = (Car*)malloc(positionSize * sizeof(Car));
    for (int i = 0; i < positionSize; i++) {
        cars[i].pos = position[i];
        cars[i].speed = speed[i];
    }
    qsort(cars, positionSize, sizeof(Car), compare);
    int fleets = 0;
    double lastTime = -1.0;
    for (int i = 0; i < positionSize; i++) {
        double time = (double)(target - cars[i].pos) / cars[i].speed;
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
    }
    free(cars);
    return fleets;
}
int main() {
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int target = 12;
    int n = 5;
    printf("%d\n", carFleet(target, position, n, speed, n));
    return 0;
}