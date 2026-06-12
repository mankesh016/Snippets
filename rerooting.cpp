#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 4e5 + 5;


#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...)
#endif


vector<int> gr[N];
int sub[N], answer[N];
int n;

void dfs(int cur, int p) {
    sub[cur] = 1;
    for (auto x : gr[cur]) {
        if (x != p) {
            dfs(x, cur);
            sub[cur] += sub[x];
        }
    }
}

void dfs2(int cur, int p) {
    for (auto x : gr[cur]) {
        if (x != p) {
        
            answer[x] = answer[cur] - sub[x] + n - sub[x];
            // answer[child] = answer[par] + n - 2* sub[child]
            dfs2(x, cur);
        }
    }
}

// re-rooting
signed main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    
    for (int i = 1; i < n; i++) {
        int a, b; cin >> a >> b;
        gr[a].push_back(b);
        gr[b].push_back(a);
    }
    
    dfs(1, 0);
    answer[1] = accumulate(sub + 1, sub + n + 1, 0ll);
    dfs2(1, 0);
    
    int ans = *max_element(answer + 1, answer + n + 1);
    cout << ans << "\n";
}
