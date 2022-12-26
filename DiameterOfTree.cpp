/* Thorem->
1.-> with any root taking as root node find max depth of tree 
the Nodemax-> max depth node will be an end of diameter for sure .

2-> taking Nodemax as root node , again find max depth of tree  
now the max depth will be called diameter of tree

*/

#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
vector<int> graph[N];
int depth[N];

void dfs(int v,int p=-1){ // v-> vertex  , p-> parent
    for(auto child:graph[v]){
        if(child==p)continue;
        depth[child] = depth[v]+1;
        dfs(child,v);
    }
}


int main(){
int n;cin>>n; // no of edges
for(int i= 1 ; i <=n;i++){
    int v1,v2;
    cin>>v1>>v2;
    graph[v1].push_back(v2);
    graph[v2].push_back(v1);
}

// finding max depth by taking any node as root node 
// lets say we take 1 as root node
dfs(1); // -1 default parent value
int max_depth = -1; // default max depth
int max_depth_index ; // store index value of max depth

for(int i=1;i<=n;i++){
    if(max_depth<depth[i]){
        max_depth = depth[i];
        max_depth_index = i;
    }
    depth[i]=0;
}

// memset(depth,0,sizeof(depth)); // resetting the depth array
dfs(max_depth_index);// taking prv_maxdepth as root node
// now in depth array tha max depth will be diameter
int diameter = max_depth;
for(int i= 1;i<=n;i++){
    if(diameter<depth[i]){
        diameter = depth[i];
    }
}
cout<<diameter<<endl;

 
}