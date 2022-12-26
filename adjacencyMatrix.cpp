// disadvantages of adajacency matrix ->
// space complexity will too much high 
// S.C = n*m;

/* advantage of adjacency matrix->
we can access any i,j index to check that whether i is connected to j or not  in O(1) t.c.  graph[i][j] =0 or not
also we can find weight of any edge in O(1) => graph[i][j] = weight 

*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;  // n-> number of vertices , m-> number of edges
    cin >> n >> m;

    int graph1[n + 1][m + 1];
    // taking input for n edges 
    // input formate will be 
    // a b -> vertex a is connected to vertex b

    for (int i = 0;i < m;++i) {
        int v1, v2; // vertex 1,2
        cin >> v1 >> v2;
        graph1[v1][v2] = 1; // v1 is connected with v2
        graph1[v2][v1] = 1; // v2 is also connected with v1  , 

    }



    return 0;
}