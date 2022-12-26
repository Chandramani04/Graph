/*
    find number of connected components in the given graph ?
    a c.c. is a part of a graph from in which every node can be accessed from every other node
    single node is also a c.c. in itself

    No of times dfs functions runs = number of c.c
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N];
bool visited[N];


void dfs(int vertex) {
    visited[vertex] = true;
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

    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(visited[i])continue;
        dfs(i);
        cnt++;
    }
    cout<<cnt<<endl;  // prints 3 c.c.
    /*
        how 3->
    1.    1 2 3 
          4 5   
    2.   6 7
    3. 8 (solo)
    
    */

}