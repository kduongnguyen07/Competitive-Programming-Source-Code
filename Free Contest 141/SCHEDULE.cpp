#include <bits/stdc++.h>
using namespace std;
const int maxN = 2e6 + 10;
typedef pair<int, int> pii;
typedef long long ll;
int n;
pii tme[maxN];
bool cmp(pii x, pii y){return (x.first < y.first || (x.first == y.first && x.second < y.second));}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>n;
    int ns = 0;
    for (int i = 1;i <= n; ++i)
    {
        int s, t; cin>>s>>t;
        tme[++ns] = {s, 1};
        tme[++ns] = {t, 0};
    }
    sort(tme + 1, tme + ns + 1, cmp);
    ll ans = 0;
    int cnt = 0;
    for (int i = 1;i <= 2 * n; ++i)
        if (tme[i].second == 1)
        {
            ans += cnt;
            ++cnt;
        }
        else --cnt;
    cout<<ans<<"\n";
    return 0;
}
