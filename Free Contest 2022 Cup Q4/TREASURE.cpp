#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;

int n, m, a[N], b[N], A[N], B[N];
map<pair<int, int>, int> mp;

struct SuffixAutomaton {
  int sz, last, len[N], link[N];
  unordered_map<int, int> next[N];

  SuffixAutomaton() {
    len[0] = 0;
    link[0] = -1;
    sz = 1;
    last = 0;
  }

  void extend(int c) {
    int cur = sz++, p;
    for (p = last; p != -1 && !next[p].count(c); p = link[p]) {
      next[p][c] = cur;
    }
    if (p != -1) {
      int q = next[p][c];
      if (len[p] + 1 == len[q]) {
        link[cur] = q;
      } else {
        int clone = sz++;
        len[clone] = len[p] + 1;
        link[clone] = link[q];
        next[clone] = next[q];
        for (; p != -1 && next[p].count(c) && next[p][c] == q; p = link[p]) {
          next[p][c] = clone;
        }
        link[cur] = link[q] = clone;
      }
    }

    last = cur;
  }
} sa;

void normalize(int n, int a[], int A[]) {
  for (int i = 1; i < n; ++i) {
    auto p = make_pair(a[i], a[i + 1]);
    int g = __gcd(a[i], a[i + 1]);
    p.first /= g;
    p.second /= g;

    auto it = mp.find(p);
    if (it == mp.end()) {
      A[i] = mp.size() + 1;
      mp[p] = A[i];
    } else {
      A[i] = it->second;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  normalize(n, a, A);
  normalize(m, b, B);

  for (int i = 1; i < n; ++i) {
    sa.extend(A[i]);
  }

  int ans = 0, cur = 0, len = 0;
  for (int i = 1; i < m; ++i) {
    while (cur && !sa.next[cur].count(B[i])) {
      cur = sa.link[cur];
      len = sa.len[cur];
    }
    if (sa.next[cur].count(B[i])) {
      cur = sa.next[cur][B[i]];
      ++len;
    }
    ans = max(ans, len);
  }
  cout << (ans + 1) << '\n';

  return 0;
}
