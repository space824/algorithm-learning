#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
int count;

int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y, int mark)
{
    if (visited[x][y] || grid[x][y] == 0)
        return;
    visited[x][y] = true;
    grid[x][y] = mark;
    count++;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dir[i][0];
        int ny = y + dir[i][1];
        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
            continue;
        dfs(grid, visited, nx, ny, mark);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    unordered_map<int, int> island_sizes;
    int mark = 2;
    bool isAllGrid = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
                isAllGrid = false;
            if (grid[i][j] == 1 && !visited[i][j])
            {
                count = 0;
                dfs(grid, visited, i, j, mark);
                island_sizes[mark] = count;
                mark++;
            }
        }
    }
    if (isAllGrid)
    {
        cout << n * m << endl;
        return 0;
    }

    // 添加陆地
    int result = 0;
    unordered_set<int> visitedIslands;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            count = 1;
            visitedIslands.clear();
            if (grid[i][j] == 0)
            {
                for (int i = 0; i < 4; i++)
                {
                    int nx = i + dir[i][0];
                    int ny = j + dir[i][1];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                        continue;
                    if (visitedIslands.count(grid[nx][ny]))
                        continue;
                    count += island_sizes[grid[nx][ny]];
                    visitedIslands.insert(grid[nx][ny]);
                }
            }
            result = max(result, count);
        }
    }
    cout << result << endl;
}