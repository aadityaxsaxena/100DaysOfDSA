/*Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges. The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes a direct edge from vertex u to v. Find the number of strongly connected components in the graph.
Examples:
Input: V = 5, E = 5, edges[][] = [[0, 2], [0, 3], [1, 0], [2, 1], [3, 4]]
Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.
Input: V = 3, E = 3, edges[][] = [[0, 1], [1, 2], [2, 0]]
Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.
Input: V = 2, E = 1, edges[][] = [[0, 1]]
Output: 2
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100
int V, E;
int adj[MAX][MAX], transpose[MAX][MAX];
int visited[MAX];
int stack[MAX], top = -1;
void push(int v) {
    stack[++top] = v;
}
int pop() {
    return stack[top--];
}
void dfs1(int node) {
    visited[node] = 1;
    for (int i = 0; i < V; i++) {
        if (adj[node][i] && !visited[i]) {
            dfs1(i);
        }
    }
    push(node);
}
void dfs2(int node) {
    visited[node] = 1;
    for (int i = 0; i < V; i++) {
        if (transpose[node][i] && !visited[i]) {
            dfs2(i);
        }
    }
}
int kosaraju() {
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            transpose[j][i] = adj[i][j];
        }
    }
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }
    int scc = 0;
    while (top != -1) {
        int node = pop();
        if (!visited[node]) {
            dfs2(node);
            scc++;
        }
    }
    return scc;
}
int main() {
    scanf("%d %d", &V, &E);
    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        for (int j = 0; j < V; j++) {
            adj[i][j] = 0;
            transpose[i][j] = 0;
        }
    }
    int u, v;
    for (int i = 0; i < E; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    int result = kosaraju();
    printf("%d\n", result);
    return 0;
}