#include <vector>
using namespace std;
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {

    vector<int>dist(n+1, 1e8);
    dist[src]=0;
    // //travesre n-1 times
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
         
            if(dist[u] + wt < dist[v]) 
            {
                dist[v] = dist[u] + wt;
            } 
        }        
    } 
        return dist;
        
}