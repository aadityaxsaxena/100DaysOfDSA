/*You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.
Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.*/

#include <stdio.h>
#define MAX 100
typedef struct {
    int x, y;
} Node;
Node queue[MAX * MAX];
int front = 0, rear = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int rows = gridSize;
    int cols = gridColSize[0];
    int fresh = 0;
    front = rear = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == 2) {
                queue[rear++] = (Node){i, j};
            }
            if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    if (fresh == 0) return 0;
    if (fresh > 0 && front == rear) return -1;
    int minutes = 0;
    while (front < rear) {
        int size = rear - front;
        int infected = 0;
        for (int i = 0; i < size; i++) {
            Node cur = queue[front++];
            for (int d = 0; d < 4; d++) {
                int nx = cur.x + dx[d];
                int ny = cur.y + dy[d];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    queue[rear++] = (Node){nx, ny};
                    fresh--;
                    infected = 1;
                }
            }
        }
        if (infected) minutes++;
    }
    return (fresh == 0) ? minutes : -1;
}