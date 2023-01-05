#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
ll a[N],n,m,k,b[N],bit[N];
void add(int p,int val)
{
    for(int i=p;i<=n;i+=(i&(-i))) bit[i]+=val;
}
ll get(ll p)
{
    ll res=0;
    for(int i=p;i>0;i-=(i&(-i))) res+=bit[i];
    return res;
}
bool kt(ll val)
{
    ll vt,tmp,ans=0;
    for(int i=1;i<=n;i++) bit[i]=0;
    for(int i=1;i<=n;i++)
    {
        tmp=b[a[i]]-val;
        if(tmp>=0) ans++;
        if(tmp>=b[1])
        {
            //cout<<tmp<<' ';
            if(tmp>=b[m]) tmp=m+1;
            else
            tmp=upper_bound(b+1,b+m+1,tmp)-b;
            ans+=get(tmp-1);
        }
        add(a[i],1);
    }
    if(ans>=k) return 1;
    return 0;
}
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) {cin>>m;a[i]=a[i-1]+m;b[i]=a[i];}
    sort(b+1,b+n+1);
    m=unique(b+1,b+n+1)-b-1;
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(b+1,b+m+1,a[i])-b;
    }
    ll l=-1e14,r=1e14,mid,ans=0;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(kt(mid)) ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
