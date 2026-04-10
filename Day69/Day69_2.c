/*You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.
Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
*/

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#define INF INT_MAX
int minDistance(int dist[], bool visited[], int n) {
    int min = INF, index = -1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i] && dist[i] < min) {
            min = dist[i];
            index = i;
        }
    }
    return index;
}
int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k) {
    int graph[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }
    for (int i = 0; i < timesSize; i++) {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        graph[u][v] = w;
    }
    int dist[n+1];
    bool visited[n+1];
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
        visited[i] = false;
    }
    dist[k] = 0;
    for (int i = 1; i <= n; i++) {
        int u = minDistance(dist, visited, n);
        if (u == -1) break;
        visited[u] = true;
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && graph[u][v] != INF &&
                dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v]) {
                
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    int maxTime = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF) return -1;
        if (dist[i] > maxTime) maxTime = dist[i];
    }
    return maxTime;
}