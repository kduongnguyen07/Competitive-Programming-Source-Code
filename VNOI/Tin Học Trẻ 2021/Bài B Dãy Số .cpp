#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n, a[1000005], pre[1000005];
map<ll, ll> minpre;
map<ll, ll> check;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    ll res = -1e18;
    minpre[a[1]] = a[1];
    check[a[1]] = true;
    pre[1] = a[1];
    for(int i = 2 ; i <= n; i++)
    {
        if(check[a[i]])
        {
            res = max(res, pre[i] - minpre[a[i]] + a[i]);
            minpre[a[i]] = min(minpre[a[i]], pre[i]);
        }
        else
        {
            minpre[a[i]] = pre[i];
            check[a[i]] =true;
        }
    }
    cout << res;
return 0;
}