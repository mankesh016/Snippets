class Dsu {
	vector<int> par, sz;
public:
	Dsu(int n) {
		sz.assign(n + 1, 1);
		par.resize(n + 1);
		iota(par.begin(), par.end(), 0);
	}

	int find(int x) {
		if (par[x] == x) return x;
		return par[x] = find(par[x]);
	}

	bool unite(int x, int y) {

		x = find(x);
		y = find(y);
		if (x == y) return false;

		if (sz[x] > sz[y]) swap(x, y);

		par[x] = y;
		sz[y] += sz[x];

		return true;
	}
};

// Dsu dsu(n);
// dsu.unite(x, y)
