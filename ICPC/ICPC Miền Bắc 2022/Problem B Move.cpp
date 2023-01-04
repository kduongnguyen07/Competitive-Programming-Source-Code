#include <bits/stdc++.h>
using namespace std;
#define ll long long
void solve() {
    ll m, s, n; cin >> m >> n >> s;
    vector<pair<int,int>> moves(n);
    for (auto& [a, b] : moves) cin >> a >> b;
    vector<int> dist(m, -1);
    dist[s] = 0;
    queue<int> qu;
    qu.push(s);
    while (!qu.empty()) {
        ll u = qu.front(); qu.pop();
        for (const auto& [a, b] : moves) {
            ll v = (u * a + b) % m;
            if (dist[v] < 0) {
                dist[v] = dist[u] + 1;
                qu.push(v);
            }
        }
    }
    cout << dist[0] << endl;
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    solve();
    return 0;
}
