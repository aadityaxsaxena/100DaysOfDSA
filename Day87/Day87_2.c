/*Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.
Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4
Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30
Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23
*/

#include <stdio.h>
int canFinish(int piles[], int n, int h, int k) {
    long long hours = 0;  // FIX: use long long
    for (int i = 0; i < n; i++) {
        hours += ((long long)piles[i] + k - 1) / k;
        if (hours > h)
            return 0;
    }
    return hours <= h;
}
int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1, right = 0;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right)
            right = piles[i];
    }
    int ans = right;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canFinish(piles, pilesSize, h, mid)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}