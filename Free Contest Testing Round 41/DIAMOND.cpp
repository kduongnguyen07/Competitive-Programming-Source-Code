#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
#define ll long long
#define vt vector
#define pb push_back
#define fi first
#define se second
#define forr(i, a, b) for(int i = a; i < b; i++)
#define dorr(i, a, b) for(int i = a; i >= b; i--)
typedef unsigned long long ull;
#define pii pair<int, int>
#define pll pair<ll, ll>
const int mxn = 1e5;
int n, k;
ll a[mxn + 1], b[mxn + 1];
bool ck(long double  mid){
    vt<long double>v;
    for(int i = 0; i < n; i++){
        v.pb(a[i] - (b[i] * mid));
    }
    sort(v.rbegin(), v.rend());
    long double res = 0;
    for(int i = 0; i < k; i++)res += v[i];
    return(res >= 0);
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    forr(i, 0, n){
        cin >> a[i] >> b[i];
    }
    long double l = 1.0 / 1e6, r = 1e6, ans;
    for(int i = 0; i < 100; i++){
        long double mid = (l + r) / 2.0;
        if(ck(mid)){
            ans = mid; l = mid;
        }else{
            r = mid;
        }
    }
    vt<pair<long double, int>>v;
    forr(i, 0, n)v.pb({a[i] - (b[i] * ans), i});
    sort(v.rbegin(), v.rend());
    ll crx = 0, cry = 0;
    forr(i, 0, k){
        crx += a[v[i].se]; cry += b[v[i].se];
    }
    ll g = __gcd(crx, cry);
    cout << crx / g << " " << cry / g;
    return 0;
}
