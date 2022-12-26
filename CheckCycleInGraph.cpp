
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N];
bool visited[N];


bool dfs(int vertex , int parent) {
    visited[vertex] = true;

    bool isloopfound = false;

    for (auto child : graph[vertex]) {
        if(visited[child]==true and child ==parent)continue;
        if (visited[child])return true;
      isloopfound |=  dfs(child,vertex);
    }
    return isloopfound;
}

int main() {
    int n, m;
    cin >> n >> m; //vertex from 1 to n 
    for (int i = 0;i < m;i++) {
        int v1, v2;cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    int targetnode = 1; // we have to check isloopexist for target node 

    bool isloopexist = false;
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        if(dfs(i,targetnode)){
            isloopexist = true;
            break;
        }
    }
    cout<<isloopexist<<endl;



}