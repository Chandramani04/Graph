#include <bits/stdc++.h>
using namespace std;
int main(){
 
// in adj. list we store number of vertexs , a given vertex is connected with
// 0 -> 1, 2, 
// 1-> 0, 3 ,4 
// space complexity of adjacency list will be => O(n+m);



// we have to create a vector of vectors of size n(vertex)
int n,m;
cin>>n>>m; // n-> vertex/node   m-> edges
vector<vector<int>>graph(n+1); // vector<int> graph[N] , can also be used
for(int i=0;i<m;i++){
    int v1,v2;
    cin>>v1>>v2;
    graph[v2].push_back(v1);
    graph[v1].push_back(v2);

}

// if weight is also given
vector<vector<pair<int,int>>>graph1(n+1);

for(int i=0;i<m;i++){
    int v1,v2,w;
    cin>>v1>>v2>>w;
    graph1[v2].push_back(make_pair(v1,w));
    graph1[v1].push_back(make_pair(v2,w));
}

}