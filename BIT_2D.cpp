class BIT2D {
	vector<vector<int>> bit;
	int n, m;
public:
	BIT2D(int n, int m) {
		this->n = n;
		this->m = m;
		bit.assign(n + 1, vector<int>(m + 1, 0));
	}

	// update [x,y]+= delta
	void update(int x, int y, int delta) {
		for (int i = x; i <= n; i += i & -i) {
			for (int j = y; j <= m; j += j & -j) {
				bit[i][j] += delta;
			}
		}
	}

	// prefix sum from (1,1) to (x,y)
	int query(int x, int y) {
		int sum = 0;
		for (int i = x; i > 0; i -= i & -i) {
			for (int j = y; j > 0; j -= j & -j) {
				sum += bit[i][j];
			}
		}
		return sum;
	}

	// sum (x,y) to (xx,yy)
	int query(int x, int y, int xx, int yy) {
		return query(xx, yy)
		       - query(x - 1, yy)
		       - query(xx, y - 1)
		       + query(x - 1, y - 1);
	}
};

// 1 based indexing
// BIT2D bit(n, m);
// bit.update(x, y, delta);
// bit.query(x, y, xx, yy); // Sum of sub-rectangle
