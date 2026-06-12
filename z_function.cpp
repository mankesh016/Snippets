
// z_function
vector<int> z_funtion(string &s) {
    int n = s.size();
    vector<int> v(n);

    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i <= r) v[i] = min(v[i - l], r - i + 1);

        while (i + v[i] < n && s[v[i]] == s[i + v[i]]) v[i]++;
        if (r < i + v[i] - 1) {
            l = i;
            r = i + v[i] - 1;
        }
    }

    return v;
}
// AABZAABZCAABZAABZA
// 010041000810051001
