#include <iostream>
#include <vector>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int sum = 0;
    int cover = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) sum++;
            if (i - 1 >= 0 && grid[i - 1][j] == 1)
                cover++;
            if(j - 1 >= 0 && grid[i][j - 1] == 1)
                cover++;
        }
    }
    cout << 4 * sum - 2 * cover << endl;
}