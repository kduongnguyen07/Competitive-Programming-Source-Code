#include <iostream>

using namespace std;

const int LIM = 3e6 + 36;
const int MOD = 1e9 + 7;

/// x^n % MOD in O(log n)
int powMOD(int x, int n) 
{
    int res = 1;
    for (; n > 0; n >>= 1)
    {
        if (n & 1) res = (1LL * res * x) % MOD;
        x = (1LL * x * x) % MOD;
    }

    return res;
}

/// fact[n] = n!
int fact[LIM];
int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    fact[0] = 1;
    for (int i = 1; i <= n + m + k; ++i)
        fact[i] = (1LL * fact[i - 1] * i) % MOD; /// n! = (n - 1)! * n

    int res = fact[n + m + k]; /// res := (n + m + k)!
    res = (1LL * res * powMOD(fact[n], MOD - 2)) % MOD; /// res := res / n!
    res = (1LL * res * powMOD(fact[m], MOD - 2)) % MOD; /// res := res / m!
    res = (1LL * res * powMOD(fact[k], MOD - 2)) % MOD; /// res := res / k!
    cout << res;
    return 0;
}
