#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k, rem = 0;
  cin >> k;
  for (int i = 1; i <= k; ++i) {
    rem = (10 * rem + 1) % k;
    if (rem == 0) {
      cout << i << '\n';
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
