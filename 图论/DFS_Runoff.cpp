#include <iostream>
#include <vector>
using namespace std;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void dfs (vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
   if (visited[x][y])
       return;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) continue;
        if (grid[x][y] < grid[nx][ny]) continue;
        dfs(grid, visited, nx, ny);
    }
    return;
}

bool isResult (vector<vector<int>>& grid, int x, int y) {
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    dfs(grid, visited, x, y);
    bool isFirst = false;
    bool isSecond = false;

    for (int j = 0; j < grid[0].size(); j++) {
        if (visited[0][j]) {
            isFirst = true;
            break;
        }
    }

    for (int i = 0; i < grid.size(); i++) {
        if (visited[i][0]) {
            isFirst = true;
            break;
        }
    }

    for (int j = 0; j < grid[0].size(); j++) {
        if (visited[grid.size() - 1][j]) {
            isSecond = true;
            break;
        }
    }

    for (int i = 0; i < grid.size(); i++) {
        if (visited[i][grid[0].size() - 1]) {
            isSecond = true;
            break;
        }
    }
    if (isFirst && isSecond) {
        return true;
    }
    return false;
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
        for (int j = 0; j < m; j++) {
            if (isResult(grid, i, j)) {
                cout << i << " " << j << endl;
            }
        }
    }
}