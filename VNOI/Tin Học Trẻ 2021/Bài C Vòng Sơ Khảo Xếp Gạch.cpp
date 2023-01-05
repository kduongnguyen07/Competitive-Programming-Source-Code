#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(), (x).end()
vector<int> prime;
vector<int> lpf;
void sieve(int n)//kỹ thuật linear sieve
{
    prime.assign(1, 2);
    lpf.assign(n + 1, 2);
    for (int x = 3; x <= n; x += 2)
    {
        if (lpf[x] == 2) prime.push_back(lpf[x] = x);
        for (int i = 0; i < prime.size() && prime[i] <= lpf[x] && prime[i] * x <= n; ++i)
            lpf[prime[i] * x] = prime[i];
    }
}
int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    sieve(1e6 + 61);
    vector<ll> multi(prime.size() - 1);
    for (int i = 0; i < multi.size(); ++i)
        multi[i] = 1LL * prime[i] * prime[i + 1];
    int q;
    cin >> q;
    while (q-->0)
    {
        ll n;
        cin >> n;
        cout << n-*--upper_bound(all(multi), n) <<endl;
    }
    return 0;
}