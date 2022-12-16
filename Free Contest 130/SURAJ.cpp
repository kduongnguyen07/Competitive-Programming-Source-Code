#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int q;
    cin >> q;
    while (q-->0)
    {
        ll m;
        int k;
        cin >> m >> k;
        ll n = m / k;
        int x = 0;
        for (int l = 0, r = sqrt(m); l <= r; )
        {
            int t = (l + r) >> 1;
            if (1LL * t * (t + 1) / 2 <= n)
            {
                x = t;
                l = t + 1;
            }
            else 
            {
                r = t - 1;
            }
        }
        
        ll v = 1LL * x * (x + 1) / 2;
        ll res = 1LL * x * k + (m - v * k) / (x + 1);
        cout << res <<endl;
    }
    return 0;
}