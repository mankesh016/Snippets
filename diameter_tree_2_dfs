#include<bits/stdc++.h>
using namespace std;

#ifdef cp_first
#include "algo/debug.h"
#else
#define debug(...)
#endif

#define int long long
const int N = 4e5 + 5;

vector<int> gr[N];
int par[N], sub[N];

void dfs(int cur, int p, vector<int> & dep) {
    par[cur] = p;

    sub[cur] = 1;
    for (auto x : gr[cur]) {
        if (x != p) {
            dep[x] = dep[cur] + 1;
            dfs(x, cur, dep);
            sub[cur] += sub[x];
        }
    }
}


signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    // int TC; cin >> TC; while (TC--)
    {
        int n; cin >> n;

        // for (int i = 0; i <= n; i++) {
        //  gr[i].clear();
        // }

        for (int i = 1; i <= n - 1; i++) {
            int x, y; cin >> x >> y;
            gr[x].push_back(y);
            gr[y].push_back(x);
        }

        vector<int> dist(n + 1);
        dfs(1, 0, dist);

        int root1 = max_element(dist.begin() + 1, dist.end()) - dist.begin();
        vector<int> dist1(n + 1);
        dfs(root1, 0, dist1);

        int root2 = max_element(dist1.begin() + 1, dist1.end()) - dist1.begin();
        // vector<int> dist2(n + 1);
        // dfs(root2, 0, dist2);

        int diameter = *max_element(dist1.begin() + 1, dist1.end());
        cout << "diameter of tree : " << diameter << "\n";

        // for (int i = 1; i <= n; i++) {
        //  longest distance of leaf, from node-i
        //  cout << max(dist1[i], dist2[i]) << " ";
        // }
    }

}
