/*There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.
Example 1:
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

#include <stdbool.h>
#include <stdlib.h>
bool dfs(int node, int** graph, int* visited, int* recStack, int* colSize) {
    visited[node] = 1;
    recStack[node] = 1;
    for (int i = 0; i < colSize[node]; i++) {
        int neighbor = graph[node][i];
        if (!visited[neighbor]) {
            if (dfs(neighbor, graph, visited, recStack, colSize))
                return true;
        } 
        else if (recStack[neighbor]) {
            return true;
        }
    }
    recStack[node] = 0;
    return false;
}
bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    int** graph = (int**)malloc(numCourses * sizeof(int*));
    int* colSize = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][1];
        colSize[u]++;
    }
    for (int i = 0; i < numCourses; i++) {
        graph[i] = (int*)malloc(colSize[i] * sizeof(int));
        colSize[i] = 0; // reset for filling
    }
    for (int i = 0; i < prerequisitesSize; i++) {
        int u = prerequisites[i][1];
        int v = prerequisites[i][0];
        graph[u][colSize[u]++] = v;
    }
    int* visited = (int*)calloc(numCourses, sizeof(int));
    int* recStack = (int*)calloc(numCourses, sizeof(int));
    for (int i = 0; i < numCourses; i++) {
        if (!visited[i]) {
            if (dfs(i, graph, visited, recStack, colSize))
                return false;
        }
    }
    return true;
}