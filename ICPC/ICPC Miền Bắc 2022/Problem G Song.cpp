#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
#define ff first
#define ss second
const int N = 2000 + 20;
const int MOD = 1e9 + 7;
int main() {
    cin.tie(NULL)->sync_with_stdio(false);
    int q; cin >> q; while (q--) {
        string s; cin >> s;
        int n = s.size();

        long long sum = 0;
        for (int i = 1; i <= n; ++i)
            (sum += ((n - i + 1) * (n - i + 2) / 2 * i + i * (i - 1) / 2 * (n - i + 1)) * (s[i - 1] - 'a' + 1)) %= MOD;
        cout << sum << '\n';
    }
}
