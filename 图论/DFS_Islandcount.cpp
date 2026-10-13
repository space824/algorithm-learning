#include <iostream>
#include <vector>
using namespace std;
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};

void dfs (const vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y) {
    if (visited[x][y] || grid[x][y] == 0) return;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int new_x = x + dir[i][0];
        int new_y = y + dir[i][1];
        if (new_x < 0 || new_x >= grid.size() || new_y < 0 ||new_y >= grid[0].size()) continue;
        dfs(grid, visited, new_x, new_y);
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

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int island_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == 1) {
                island_count++;
                dfs(grid, visited, i, j);
            }
        }
    }
    cout << island_count << endl;
}