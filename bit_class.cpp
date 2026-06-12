class BIT {
    vector<int> bit;
    int n;
public:
    BIT(int n) {
        this->n = n;
        bit.assign(n + 1, 0);
    }
    void update(int idx, int delta) {
        for ( ; idx <= n; idx += idx & -idx) bit[idx] += delta;
    }
    int query(int idx) {
        int sum = 0;
        for ( ; idx > 0; idx -= idx & -idx) sum += bit[idx];
        return sum;
    }
};

// 1 based indexing
// BIT bit(n);
// bit.query(idx); // returns prefix sum till index
// bit.update(idx, delta);
