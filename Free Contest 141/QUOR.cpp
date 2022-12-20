#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll Mod = 1e9 + 7;

int a[202];
int f[201][201][1001];
int n, k;

void add(int &a, ll b)
{
	a = (a * 1ll + b) % Mod;
}

int dp(int pos, int op, int val)
{
	
	if(op < 0) return 0;
	if(val > k) return 0;
	if(val < 0) return 0;
	if(pos > n) return op == 0;
	
	int &res = f[pos][op][val];
	if(res != -1) return res;
	
	int dif = a[pos + 1] - a[pos];
	res = 0; 
		
	add(res, dp(pos + 1, op, val + op * dif));
	add(res, dp(pos + 1, op, val + op * dif) * 1ll * op);
	add(res, dp(pos + 1, op + 1, val + (op + 1) * dif));
	add(res, dp(pos + 1, op - 1, val + (op - 1) * dif) * 1ll * op);

	return res;
}

signed main(){

	while(cin >> n >> k)
	{

		for(int i = 1; i <= n; i++)
			cin >> a[i];

		sort(a + 1, a + 1 + n);
		memset(f, -1, sizeof f);
		a[n + 1] = 1e9;
		
		cout << dp(1, 0, 0) << "\n";
	}
	return 0;
}