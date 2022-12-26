#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N]; // ==  vector <vector<int>>graph(n)
bool visited[N];

/*
    time complexity of dfs -> number of vertex + number of edges
                          tc =   O(V+E)
*/


void dfs(int vertex) {
    visited[vertex] = true;
    for (auto child : graph[vertex]) {
        if (visited[child])continue;
        dfs(child);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0;i < m;i++) {
        int v1, v2;cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);

}