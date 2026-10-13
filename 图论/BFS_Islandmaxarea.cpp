#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int count;
int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y)
{
    queue<pair<int, int>> que;
    que.push({x, y});
    visited[x][y] = true;
    count++;
    while (!que.empty())
    {
        pair<int, int> cur = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int new_x = cur.first + dir[i][0];
            int new_y = cur.second + dir[i][1];
            if (new_x < 0 || new_x >= grid.size() || new_y < 0 || new_y >= grid[0].size())
                continue;
            if (!visited[new_x][new_y] && grid[new_x][new_y] == 1)
            {
                que.push({new_x, new_y});
                visited[new_x][new_y] = true;
                count++;
            }
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                count = 0;
                bfs(grid, visited, i, j);
                result = max(result, count);
            }
        }
    }
    cout << result << endl;
}