/*Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.
Note: The graph can have multiple component.
Examples:
Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation: 
1 -> 2 -> 0 -> 1 is a cycle.
Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation: 
No cycle in the graph.
*/

#include <stdio.h>
#include <stdlib.h>
int findParent(int v, int parent[]) {
    if (parent[v] == v)
        return v;
    parent[v] = findParent(parent[v], parent);
    return parent[v];
}
void unionSets(int u, int v, int parent[], int rank[]) {
    int pu = findParent(u, parent);
    int pv = findParent(v, parent);
    if (pu == pv) return;
    if (rank[pu] < rank[pv]) {
        parent[pu] = pv;
    } else if (rank[pv] < rank[pu]) {
        parent[pv] = pu;
    } else {
        parent[pv] = pu;
        rank[pu]++;
    }
}
int isCycle(int edges[][2], int E, int V) {
    int *parent = (int*)malloc(V * sizeof(int));
    int *rank = (int*)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    for (int i = 0; i < E; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int pu = findParent(u, parent);
        int pv = findParent(v, parent);
        if (pu == pv) {
            free(parent);
            free(rank);
            return 1;
        }
        unionSets(pu, pv, parent, rank);
    }
    free(parent);
    free(rank);
    return 0;
}