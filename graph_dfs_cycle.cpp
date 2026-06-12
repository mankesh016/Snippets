#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 4e5 + 5;


#ifdef cp_first
#include "algo/debug.h"
#else
#define debug(...)
#endif


vector<int> gr[N];
int vis[N];

void dfs(int cur, int p) {
    vis[cur] = 1;
    for (auto x : gr[cur]) {
        if (vis[x] == 0) {
            dfs(x, cur);
        }
        // else if (x != p && vis[x] == 1) {
        //     // backedge
        //     // cout << cur << "->" << x << "\n";
        // }
    }
    // vis[cur] = 2;
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int TC; cin >> TC; while (TC--)
    {
        int n, m; cin >> n >> m;
        
        // for (int i = 0; i <= n; i++) {
        //     gr[i].clear();
        //     vis[i] = 0;
        // }
        
        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        
        // for (int i = 1; i <= n; i++) {
        //     if (!vis[i]) dfs(i, 0);
        // }
        
        
        
        
    }
}
