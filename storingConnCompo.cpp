
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N];
bool visited[N];

vector<int>temp_cc;//store noded of a single c.c

void dfs(int vertex) {
    visited[vertex] = true;
    temp_cc.push_back(vertex);
    for (auto child : graph[vertex]) {
        if (visited[child])continue;
        dfs(child);
    }

}

int main() {
    int n, m;
    cin >> n >> m; //vertex from 1 to n 
    for (int i = 0;i < m;i++) {
        int v1, v2;cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    vector<vector<int>>cc;//store total connected components

    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        temp_cc.clear();//clear the previously stored elements
        dfs(i);
        cc.push_back(temp_cc); //storing into main cc vector
    }

    cout<<cc.size()<<endl;//total no of cc
    for(auto temp_cc:cc){
        for(auto x:temp_cc){
            cout<<x<<" ";
        }
    cout<<endl;
    }


}