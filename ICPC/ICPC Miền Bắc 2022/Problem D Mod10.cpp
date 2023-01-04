#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),_##i##_b=(b); i<=_##i##_b; i++)
using namespace std;
void solve() {
    vector<int> f(10);
    f[0] = 1;
    FOR(i,1,9) f[i] = f[i-1] * i;

    int n; cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    vector<int> res;
    while (n > 0) {
        int digit = 0;
        while (digit < 9 && f[digit+1] <= n) ++digit;
        res.push_back(digit);
        n -= f[digit];
    }

    sort(res.begin(), res.end());
    for (int x : res) cout << x;
    cout << endl;
}
int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
