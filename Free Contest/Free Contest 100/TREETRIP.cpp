#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

const long long LINF = 1000000000000000000LL;

int n, A, B;
vector< vector<long long> > dp;
vector< vector< pair<int, int> > > adj;

void DFS(int z, int last) {
	long long totalMinCost = 0;
	int children = 0;

	long long bestDelta[2] = {LINF, LINF};

	for (auto Pair: adj[z]) {
		int t = Pair.first, d = Pair.second;
		if (t == last) continue;
		children++; DFS(t, z);

		long long delta = dp[t][1] + 1LL * d * A - B - min(dp[t][0], dp[t][1]);
		if (delta < bestDelta[0]) {
            bestDelta[1] = bestDelta[0];
            bestDelta[0] = delta;
		} else
            bestDelta[1] = min(bestDelta[1], delta);

		totalMinCost += min(dp[t][0], dp[t][1]) + B;
	}

	dp[z][1] = min(totalMinCost, totalMinCost + bestDelta[0]);
	if (children > 1)
		dp[z][0] = totalMinCost + bestDelta[0] + bestDelta[1];
}

void Input() {
	cin >> n >> A >> B; adj.resize(n);
	dp.resize(n, vector<long long>(2, LINF));
	for (int i=1; i<n; i++) {
		int x, y, w; cin >> x >> y >> w; x--; y--;
		adj[x].push_back({y, w}); adj[y].push_back({x, w});
	}
}

void Solve() {
    long long ans;
    if (n == 2) {
        int w = adj[0][0].second;
        ans = 2 * min(1LL*w*A, 1LL*B);
	} else {
	    DFS(0, -1);
	    ans = min(dp[0][0], dp[0][1]) + B;
	}
	cout << ans << endl;
}

int main(int argc, char* argv[]) {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); Input(); Solve();
	return 0;
}
