/*
concept -> precomputation of subtree sum
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;
vector<int>graph[N];
int subtreesum[N];
int value[N];//value corresponding to each vertex , given in problem
const int M = 1e9+7;

void dfs(int v,int p=-1){
    subtreesum[v]+=v;
    for(auto child:graph[v]){
        if(child==p)continue;
        dfs(child,v);
        subtreesum[v] +=subtreesum[child];
    }
}

int main(){ 
int n;cin>>n;
for(int i =1;i<=n;i++){
    int x,y;cin>>x>>y;
    graph[x].push_back(y);
    graph[y].push_back(x);
}
for(int i=1;i<=n;i++){
    cin>>value[i];
}

dfs(1,0);
long long ans = 0;
for(int i=1;i<=n;i++){
    int currentsum = subtreesum[i];
    int remainingsum = subtreesum[1]-currentsum;
    ans = max(ans,(currentsum*1ll*remainingsum)%M);
}
cout<<ans<<endl;
 
}