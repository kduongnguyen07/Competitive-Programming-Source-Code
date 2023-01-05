#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,l,r) for(ll i = l; i <= r; ++i)
#define FOD(i,l,r) for(ll i = l; i >= r; --i)
#define ii pair<ll,ll>
#define fi first
#define se second
ll n, m;
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    FOR(i,1,n) {
        FOR(i,1,m) {
            ll x; cin >> x;
            if(x) cout << "0 ";
            else cout << "1 ";
        }
        cout << "\n";
    }
    return 0;
}