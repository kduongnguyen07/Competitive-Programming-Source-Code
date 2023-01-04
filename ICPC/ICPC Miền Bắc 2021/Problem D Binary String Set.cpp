#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int q; cin >>q;
    while (q--) {
        string s; cin >> s;
        int n = SZ(s);
        s = " " + s + " ";
        vector<int> f(n + 1);
        f[0] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] = n;

            if (s[i] == '0') {
                f[i] = min(f[i], f[i-1]);
                if (i >= 2 && s[i-1] == '1') f[i] = min(f[i], f[i-2]);
            } else {
                assert(s[i] == '1');
                f[i] = min(f[i], f[i-1] + 1);
                if (i >= 2 && s[i-1] == '0') f[i] = min(f[i], f[i-2]);
            }
        }
        cout << f.back() <<endl;
    }
    return 0;
}
