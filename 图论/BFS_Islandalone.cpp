#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void bfs (vector<vector<int>>& grid, int x, int y) {
    queue<pair<int, int>> que;
    que.push({x, y});
    grid[x][y] = 0;
    while (!que.empty()) {
        pair<int, int> cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
                continue;
            if (grid[nx][ny] == 1) {
                que.push({nx, ny});
                grid[nx][ny] = 0;
            }
            
        }
    }
}

int main () {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        if (grid[i][0] == 1)
            bfs(grid, i, 0);
        if (grid[i][m - 1] == 1)
            bfs(grid, i, m - 1);
    }

    for (int j = 0; j < m; j++) {
        if (grid[0][j] == 1)
            bfs(grid, 0, j);
        if (grid[n - 1][j] == 1)
            bfs(grid, n - 1, j);
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                count++;
            }
        }
    }
    cout << count << endl;
}