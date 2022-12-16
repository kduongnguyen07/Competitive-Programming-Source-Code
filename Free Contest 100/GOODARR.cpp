#include <bits/stdc++.h>

using namespace std;

int n, maxA;
vector<int> a;
vector<vector<int> > pos;

long long C2(int n) {
    return 1LL*n*(n-1)/2;
}

struct Node {
    long long sum, valK, valD; // possible bug: valK as int
};

long long arithSum(long long k, long long d, int len) {
    return k*len + C2(len)*d; // possible bug: forget 1LL
}

struct IT {
private:
    int n;
    vector<Node> t;

    vector<bool> isModified;
    vector<int> save;

    void propagate(int id, int l, int r) {
        long long &k = t[id].valK, &d = t[id].valD;
        if (k != 0 || d != 0) {
            int m = (l+r)/2;
            long long kRight = k + (m-l+1)*d; // possible bug: kRight as int

            t[2*id].valK += k; t[2*id+1].valK += kRight;
            t[2*id].valD += d; t[2*id+1].valD += d;
            t[2*id].sum += arithSum(k, d, m-l+1); t[2*id+1].sum += arithSum(kRight, d, r-m);

            k = d = 0;
        }
    }

    void update(int id, int l, int r, int i, int j, int k, int d) {
        if (!isModified[id]) {
            isModified[id] = true;
            save.push_back(id);
        }

        if (i > r || j < l) return;
        if (i <= l && r <= j) {
            t[id].valK += k;
            t[id].valD += d;
            t[id].sum += arithSum(k, d, r-l+1);
            return;
        }

        propagate(id, l, r);
        int m = (l+r)/2;
        update(2*id, l, m, i, j, k, d); update(2*id+1, m+1, r, i, j, k + max(0, m-max(i, l)+1)*d, d);

        t[id].sum = t[2*id].sum + t[2*id+1].sum;
    }

    long long query(int id, int l, int r, int i, int j) {
        if (!isModified[id]) {
            isModified[id] = true;
            save.push_back(id);
        }

        if (i > r || j < l) return 0;
        if (i <= l && r <= j) return t[id].sum;
        propagate(id, l, r);
        int m = (l+r)/2;
        return query(2*id, l, m, i, j) + query(2*id+1, m+1, r, i, j);
    }

public:
    IT(int n): n(n) {
        t.assign(4*n+1, {0, 0, 0});
        isModified.assign(4*n+1, false);
    }

    void update(int l, int r, int k, int d) {
        update(1, 1, n, l, r, k, d);
    }

    long long query(int l, int r) {
        return query(1, 1, n, l, r);
    }

    void rollback() {
        for(int id: save) {
            t[id] = {0, 0, 0};
            isModified[id] = false;
        }
        save.clear();
    }
};

int main() {
    scanf("%d", &n);
    a.resize(n+1);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);

    maxA = *max_element(a.begin(), a.end());

    pos.assign(maxA+1, vector<int>());

    for(int x = 1; x <= maxA; ++x)
        pos[x].push_back(0);
    for(int i = 1; i <= n; ++i)
        pos[a[i]].push_back(i);
    for(int x = 1; x <= maxA; ++x)
        pos[x].push_back(n+1);

    IT t(2*n+1);

    long long ans = 0;
    for(int x = 1; x <= maxA; ++x) {
        int cnt = 0;

        for(int i = 1; i < pos[x].size(); ++i) {
            int a = 2*cnt - (pos[x][i] - 1) + n+1;
            int b = 2*cnt - pos[x][i-1] + n+1;

            ans += t.query(max(1, a-1), b-1); //possible bug: 1) forget taking max with 1; 2) max(1, b-1)

            t.update(a, b, 1, 1);
            t.update(b+1, 2*n+1, b-a+1, 0);

            ++cnt;
        }

        t.rollback();
    }

    ans = C2(n+1) - ans;
    printf("%lld", ans);

    return 0;
}
