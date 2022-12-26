#include <bits/stdc++.h>
using namespace std;
const int N = 1e3;
vector<int> graph[N]; // ==  vector <vector<int>>graph(n)
bool visited[N];
int subtreesum[N]; // prefix sum array of subtree
int evencnt[N];  // prefix  count array of even vertex

void dfs(int vertex) {
    visited[vertex] = true;
    if(vertex%2==0)evencnt[vertex]++;
    subtreesum[vertex]+=vertex;
    for (auto child : graph[vertex]) {
        if (visited[child])continue;
        dfs(child);
        subtreesum[vertex]+=subtreesum[child];
        evencnt[vertex]+=evencnt[child];
    }
}

int main() {
    int n;
    cin >> n ;
    
    for (int i = 0;i <n;i++) {
        int v1, v2;cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    dfs(1);//calling dfs for root node -> this call will calculate subtreesum for whole tree 
    cout<<subtreesum[1]<<endl; // can find sub tree sum in O(1) 
    cout<<evencnt[1]<<endl;
}