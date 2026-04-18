/*There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
Return all critical connections in the network in any order.
Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.
Example 2:
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]
*/

#include <stdlib.h>
void dfs(int u, int parent, int* disc, int* low, int** graph, int* graphSize,
         int* time, int** result, int* returnSize) {
    disc[u] = low[u] = (*time)++;
    for (int i = 0; i < graphSize[u]; i++) {
        int v = graph[u][i];
        if (v == parent) continue;
        if (disc[v] == -1) {
            dfs(v, u, disc, low, graph, graphSize, time, result, returnSize);
            if (low[v] < low[u]) low[u] = low[v];
            if (low[v] > disc[u]) {
                result[*returnSize][0] = u;
                result[*returnSize][1] = v;
                (*returnSize)++;
            }
        } else {
            if (disc[v] < low[u]) low[u] = disc[v];
        }
    }
}
int** criticalConnections(int n, int** connections, int connectionsSize,
                         int* connectionsColSize, int* returnSize,
                         int** returnColumnSizes) {
    int* degree = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < connectionsSize; i++) {
        degree[connections[i][0]]++;
        degree[connections[i][1]]++;
    }
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(degree[i] * sizeof(int));
        degree[i] = 0; // reuse as index
    }
    for (int i = 0; i < connectionsSize; i++) {
        int u = connections[i][0];
        int v = connections[i][1];
        graph[u][degree[u]++] = v;
        graph[v][degree[v]++] = u;
    }
    int* disc = (int*)malloc(n * sizeof(int));
    int* low = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        disc[i] = -1;
        low[i] = -1;
    }
    int** result = (int**)malloc(connectionsSize * sizeof(int*));
    *returnColumnSizes = (int*)malloc(connectionsSize * sizeof(int));
    for (int i = 0; i < connectionsSize; i++) {
        result[i] = (int*)malloc(2 * sizeof(int));
        (*returnColumnSizes)[i] = 2;
    }
    *returnSize = 0;
    int time = 0;
    dfs(0, -1, disc, low, graph, degree, &time, result, returnSize);
    return result;
}