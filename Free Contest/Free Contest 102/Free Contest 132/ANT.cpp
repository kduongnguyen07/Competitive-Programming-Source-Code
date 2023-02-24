#include <bits/stdc++.h>
using namespace std;
const int Sz = 2e5 + 5;
int a[Sz];
int n, q;
signed main(){
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	while(q--){
		int l, r;
		cin >> l >> r;
		int sz = r - l + 1;
		if(sz % 2 == 1){
			cout << 1 << endl;
		}else
			cout << a[l + sz / 2] - a[l + sz / 2 - 1] + 1 << endl;
	}

	return 0;
}