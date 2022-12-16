#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

vector<int> g[10101];
int u[10101];
long long  d[10101];
int n;

long long go (int x) {
	queue<int> bfs;

	for (int i = 1; i <= n; i++){
		u[i] = 0;
		d[i] = 0;
	}

	bfs.push(x);

	u[x] = 1;
	d[x] = 1;
	
	while (!bfs.empty()){
		int t = bfs.front();
		bfs.pop();
		for (int nx : g[t]){
			if (u[nx] == 0){
				u[nx] = 1;
				d[nx] = d[t]+1;
				bfs.push(nx);
			}
		}
	}

	long long v = 0;
	for (int i = 1 ; i <= n; i++){
		if (u[i] == 0){
			return -1;
		}
		else{
			v += d[i];
		}
	}
	return v;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int m = 0;

	for (int i = 1; i <= n; i++){
		int k;
		cin >> k;
		m += k;
		for (int j = 0; j < k; j++){
			int a;
			cin >> a;
			g[a].push_back(i);
		}
	}

	long long res = -1;

	for (int i = 1; i <= n; i++){
		long long total = go(i);
		if (total != -1){
			if (res == -1) res = total;
			else res = min(res, total);
		}
	}

	cout << res << endl;
}
