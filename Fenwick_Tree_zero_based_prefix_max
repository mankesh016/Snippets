class BIT {
	vector<int> bit;
	int n;
public:
	BIT(int n) {
		this->n = n;
		bit.assign(n + 1, 0);
	}
	// supports prefix max, if update are non-decreasing:
	void update(int idx, int val) {
		for ( ; idx <= n; idx = idx | (idx + 1)) bit[idx] = max(bit[idx], val);
	}
	int query(int idx) {
		int mx = 0;
		for ( ; idx >= 0; idx = (idx & (idx + 1)) - 1) mx = max(mx, bit[idx]);
		return mx;
	}
};

// Supports zero based indexing
