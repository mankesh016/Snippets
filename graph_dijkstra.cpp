#include<bits/stdc++.h>
using namespace std;

#ifdef local
#include "algo/debug.h"
#else
#define debug(...)
#endif

#define int long long
const int N = 2e5 + 5;
const int INF = 1e18;



// using priority_queue
vector<int> dijkstra (int root, vector< vector<pair<int, int>> > &gr) {
    int n = gr.size();
    
    vector<int> dist(n, INF);
    vector<int> vis(n, 0);
    
    priority_queue<pair<int, int>, vector< pair<int, int>>, greater<pair<int, int>>> pq;
    dist[root] = 0;
    pq.push({0, root});
    
    while (!pq.empty()) {
        auto p = pq.top(); pq.pop();
        int cur = p.second, w = p.first;
        
        if (vis[cur]) continue;
        vis[cur] = 1;
        
        for (auto pp : gr[cur]) {
            int xx = pp.first, ww = pp.second;
            if (ww + w < dist[xx]) {
                dist[xx] = ww + w;
                pq.push({dist[xx], xx});
            }
        }
    }
    return dist;
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // int TC; cin >> TC; while (TC--)
    {
        int n, m; cin >> n >> m;
        
        vector< vector<pair<int, int>> > gr(n + 1), grr(n + 1);
        vector<vector<int>> edges;
        
        for (int i = 0; i < m; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
            
            gr[x].push_back({y, z});
            grr[y].push_back({x, z}); // reverse
        }
        
        vector<int> dist1 = dijkstra(1, gr);
        vector<int> dist2 = dijkstra(n, grr);
        
        int ans = INF;
        for (auto v : edges) {
            int x = v[0], y = v[1], z = v[2];
            int temp = dist1[x] + dist2[y] + z / 2; //direction metter here
            
            ans = min(ans, temp);
        }
        
        
        cout << ans << "\n";
    }
}
