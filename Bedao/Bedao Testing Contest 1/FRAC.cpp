#include <bits/stdc++.h>

using namespace std;
#define ll  long long
#define pll pair<ll,ll>
#define ff first
const ll maxn=1e7+100;
const ll mod =1e9+7;
const ll base=4e18;
map<ll,ll> cnt;
map<ll,ll> cnt1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    if (fopen("test.inp", "r"))
    {
        freopen("test.inp", "r", stdin);
        freopen("test.out", "w", stdout);
    }
    ll n;
    cin>>n ;
    if (n==0)
    {
        cout <<"impossible";
        return 0;
    }
    for (int i=1; i<=n; i++)
    {
        ll x;
        cin>> x;
        if (x==0)
        {
            cout <<"impossible";
            return 0;
        }
       for (int j=2;j*j<=x;j++)
       {
           ll sl=0;
           if (x%j==0)
           {
               while (x%j==0)
               {
                   x/=j;
                   sl++;
               }
               cnt[j]+=sl;
               cnt1[j]=max(cnt1[j],sl);
           }
       }
       if (x!=1)
       {
           cnt[x]+=1;
           cnt1[x]=max(cnt1[x],1ll);
       }

    }
    ll ans=1;
    for (auto to:cnt)
    {
        ll t=to.ff;
        ll cl=cnt[t]-cnt1[t];
        while (cl--)
            ans= ans*t;
    }
    cout <<ans<<endl;
}
