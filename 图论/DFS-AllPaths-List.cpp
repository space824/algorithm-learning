#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<vector<int>> result;
vector<int> path;

void dfs(const vector<list<int>> &graph, int x, int n) {
    if (x == n) {
        result.push_back(path);
        return;
    }
    for (int i : graph[x]) {
        path.push_back(i);
        dfs(graph, i, n);
        path.pop_back();
    }
}

int main() {
    int n, m, s, t;
    cin >> n >> m;

    vector<list<int>> graph(n + 1);

    while (m--) {
        cin >> s >> t;
        graph[s].push_back(t);
    }

    path.push_back(1);
    dfs(graph, 1, n);

    if (result.empty()) cout << "No paths found" << endl;
    for (const auto &pa : result) {
        for (int i = 0; i < pa.size() - 1; i++) {
            cout << pa[i] << " ";
        }
        cout << pa[pa.size() - 1] << endl;
    }
}