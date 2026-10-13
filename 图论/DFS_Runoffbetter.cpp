#include <iostream>
#include <vector>
using namespace std;
int n, m;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y)
{
    if (visited[x][y])
        return;

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nextx = x + dir[i][0];
        int nexty = y + dir[i][1];
        if (nextx < 0 || nextx >= n || nexty < 0 || nexty >= m)
            continue;
        if (grid[x][y] > grid[nextx][nexty])
            continue; // 注意：这里是从低向高遍历

        dfs(grid, visited, nextx, nexty);
    }
    return;
}

int main()
{

    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
        }
    }
    // 标记从第一组边界上的节点出发，可以遍历的节点
    vector<vector<bool>> firstBorder(n, vector<bool>(m, false));

    // 标记从第一组边界上的节点出发，可以遍历的节点
    vector<vector<bool>> secondBorder(n, vector<bool>(m, false));

    // 从最上和最下行的节点出发，向高处遍历
    for (int i = 0; i < n; i++)
    {
        dfs(grid, firstBorder, i, 0);      // 遍历最左列，接触第一组边界
        dfs(grid, secondBorder, i, m - 1); // 遍历最右列，接触第二组边界
    }

    // 从最左和最右列的节点出发，向高处遍历
    for (int j = 0; j < m; j++)
    {
        dfs(grid, firstBorder, 0, j);      // 遍历最上行，接触第一组边界
        dfs(grid, secondBorder, n - 1, j); // 遍历最下行，接触第二组边界
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // 如果这个节点，从第一组边界和第二组边界出发都遍历过，就是结果
            if (firstBorder[i][j] && secondBorder[i][j])
                cout << i << " " << j << endl;
            ;
        }
    }
}