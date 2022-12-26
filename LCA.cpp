/*
LCA -> lowest common ancestor  - > lca of two nodes is first common ancestor

LCA of siblings -> their first common parent
LCA of parent and child -> parent
ex->
   1
 2   3
 LCA of 2 and 3  = 1
 LCA of 1&2 or 1&3 = 1


 steps to find lca of 2 nodes A and B->
 store all vertex in the path from root to node A and B
 and the last common parent will be LCA

*/
#include <bits/stdc++.h>
using namespace std;
int const N = 1e5;
vector<int> graph[N];
int parent[N];//stores parent of each vertex , initial value -1 (root node has no par.)

void dfs(int v, int p = -1) {
    parent[v] = p;
    for (auto child : graph[v]) {
        if (child == p)continue;
        dfs(child, v);
    }
}

vector<int> path(int v) {
    vector<int>ans;
    while (v != -1) {
        ans.push_back(v);
        v = parent[v];
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
int n;cin>>n; // no of edges
for(int i= 1 ; i <=n;i++){
    int v1,v2;
    cin>>v1>>v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}

    dfs(1);
    int A, B;
    cin >> A >> B;

    vector<int> pathofA = path(A);
    vector<int> pathofB = path(B);
    int min_size = min(pathofA.size(), pathofB.size());
    int LCA = -1;//initial value of lca -1 
    
    for(int i = 0 ; i<min_size;i++){
        if(pathofA[i]==pathofB[i]){
            LCA = pathofA[i];
        }
        else{
            break;
        }
    }

    cout<<LCA<<endl;


}