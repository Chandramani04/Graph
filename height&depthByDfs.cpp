#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N];
int depth[N], height[N];

void dfs(int vertex, int parent) {
    for (auto child : graph[vertex]) {
        if (child == parent)continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
    }
}

int main() {

    int n;cin >> n ; // n->number of edges
    for (int i = 0;i < n;i++) {
        int v, e;cin >> v >> e;
        graph[v].push_back(e);
        graph[e].push_back(v);
    }
    dfs(1, 0);
    for (int i = 1;i <= n;i++) {
        cout << depth[i] << " " << height[i] << endl;
    }



}