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
int par[N][20], dep[N];


void dfs(int cur, int p) {
	dep[cur] = dep[p] + 1;

	par[cur][0] = p;
	for (int i = 1; i < 20; i++) {
		par[cur][i] = par[par[cur][i - 1]][i - 1];
	}

	for (auto x : gr[cur]) {
		if (x != p) {
			dfs(x, cur);
		}
	}
}

int kth(int x, int k) {
	for (int i = 0; i < 20; i++) {
		if (k & (1 << i)) x = par[x][i];
	}
	return x;
}

int lca(int x, int y) {
	if (dep[x] < dep[y]) swap(x, y);

	x = kth(x, dep[x] - dep[y]);
	if (x == y) return x;

	for (int i = 19; i >= 0; i--) {
		if (par[x][i] != par[y][i]) x = par[x][i], y = par[y][i];
	}
	return par[x][0];
}

signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// int TC; cin >> TC; while (TC--)
	{

		int n, q; cin >> n >> q;

		// for (int i = 0; i <= n; i++) {
		//  gr[i].clear();
		// }

		for (int i = 1; i < n; i++) {
			int x, y; cin >> x >> y;
			gr[x].push_back(y);
			gr[y].push_back(x);
		}

		dfs(1, 0);

		while (q--) {
			int x, y; cin >> x >> y;

			cout << lca(x, y) << "\n";
		}
	}
}
