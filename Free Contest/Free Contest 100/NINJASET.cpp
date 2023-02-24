#include <bits/stdc++.h>

#define all(c) c.begin(),c.end()

using namespace std;

const int MAXN = 200010;

int n, p[MAXN], v[MAXN], x[MAXN];
multiset<int> s[MAXN];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", v+i, p+i);
		x[i] = i;
	}

	for (int i = n; i >= 1; i--) {
		auto it = s[x[i]].upper_bound(v[i]-1);
		if (it != s[x[i]].end()) s[x[i]].erase(it);
		s[x[i]].insert(v[i]);
		if (s[x[i]].size() < s[x[p[i]]].size()) {
			s[x[p[i]]].insert(all(s[x[i]]));
		} else {
			s[x[i]].insert(all(s[x[p[i]]]));
			x[p[i]] = x[i];
		}
	}

	printf("%d\n", (int)s[x[0]].size());
}
