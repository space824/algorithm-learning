#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {-1, 0, 0, -1, -1, 0, 0, 1};
void dfs (vector<vector<int>>& grid, int x, int y) {
    grid[x][y] = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
        if (grid[nx][ny] == 0) continue;
        dfs(grid, nx, ny);
    }
    return;
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
        if (grid[i][0] == 1) dfs(grid, i, 0);
        if (grid[i][m - 1] == 1) dfs(grid, i, m - 1);
    }

    for (int j = 0; j < m; j++) {
        if(grid[0][j] == 1)
            dfs(grid, 0, j);
        if(grid[n - 1][j] == 1)
            dfs(grid, n - 1, j);
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