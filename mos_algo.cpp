#include<bits/stdc++.h>
using namespace std;

#ifdef cp_first
#include "algo/debug.h"
#else
#define debug(...)
#endif

#define int long long
const int N = 1e6 + 5;

int BLOCK; // sqrt(n)
int cnt[N];
long long curAns = 0;

struct Query {
	int l, r, idx;
};

bool cmp(Query &a, Query &b) {
	int block_a = a.l / BLOCK;
	int block_b = b.l / BLOCK;

	if (block_a != block_b) return block_a < block_b;
	// return a.r < b.r;

	return (block_a & 1) ? (a.r < b.r) : (a.r > b.r);
	// trick: alternate sorting by r to reduce moves
}

void add(int x) {
	curAns -= 1LL * cnt[x] * cnt[x] * x;
	cnt[x]++;
	curAns += 1LL * cnt[x] * cnt[x] * x;
}

void remove(int x) {
	curAns -= 1LL * cnt[x] * cnt[x] * x;
	cnt[x]--;
	curAns += 1LL * cnt[x] * cnt[x] * x;
}


// Mo's algorithm
signed main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	// int TC; cin >> TC; while (TC--)
	{
		int n, m; cin >> n >> m;
		BLOCK = sqrt(n);
		// reset curAns, cnt for testcases,

		vector<int> a(n);
		for (auto &x : a)cin >> x;

		vector<Query> queries;

		int l, r;
		for (int i = 0; i < m; i++) {
			cin >> l >> r;
			l--; r--;
			queries.push_back({l, r, i});
		}

		sort(queries.begin(), queries.end(), cmp);
		vector<long long> ans(m);
		int L = 0, R = -1;

		for (auto q : queries) {
			int l = q.l, r = q.r;

			while (R < r) add(a[++R]);
			while (R > r) remove(a[R--]);
			while (L < l) remove(a[L++]);
			while (L > l) add(a[--L]);

			ans[q.idx] = curAns;
		}

		for (auto x : ans) cout << x << "\n";
	}
}