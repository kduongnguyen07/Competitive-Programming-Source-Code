#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i=a, _n=b; i<=_n; ++i)
using namespace std;
const int N = 1e5+7;
int n, a[N];
struct SegmentTree {
    int val[N*4], lz[N*4];//số giá trị của cây = 4 lần số giá trị của mảng build cây
    void build(int k, int l, int r, int j) {
        if (l == r) {
            val[k] = a[r] >> j & 1;
            lz[k] = 0;
            return;
        }
        int m = (l+r) >> 1;
        build(k*2, l, m, j);
        build(k*2+1, m+1, r, j);

        val[k] = val[k*2] + val[k*2+1];
    }
    void down(int k, int l, int r, int m) {
        if (lz[k] == 0) return;
        lz[k] = 0;

        val[k*2] = m-l+1 - val[k*2];
        lz[k*2] ^= 1;

        val[k*2+1] = r-m - val[k*2+1];
        lz[k*2+1] ^= 1;
    }
    void update(int k, int l, int r, int u, int v) {
        if (v < l || r < u) return;
        if (u <=l && r <=v) {
            val[k] = r-l+1 - val[k];
            lz[k] ^= 1;
            return;
        }
        int m = (l+r) >> 1;
        down(k, l, r, m);
        update(k*2, l, m, u, v);
        update(k*2+1, m+1, r, u, v);
        val[k] = val[k*2] + val[k*2+1];
    }
    int ans(int k, int l, int r, int u, int v) {
        if (v < l || r < u) return 0;
        if (u <=l && r <=v) return val[k];
        int m = (l+r) >> 1;
        down(k, l, r, m);
        return ans(k*2, l, m, u, v) +ans(k*2+1, m+1, r, u, v);
    }
} 
st[20];
int main()
{
    cin >> n;
    FOR(i, 1, n) cin >> a[i];
    FOR(j, 0, 19) st[j].build(1, 1, n, j);
    int q; cin >> q; while (q--) {
        char cac; cin >> cac;
        if (cac == '1') {
            int u, v; cin >> u >> v;
            long long sum = 0;
            FOR(j, 0, 19) sum += (1LL << j) * st[j].ans(1, 1, n, u, v);
            cout << sum <<endl;
        } else {
            int u, v, x; cin >> u >> v >> x;
            FOR(j, 0, 19) if (x >> j & 1) st[j].update(1, 1, n, u, v);
        }
    }
}
