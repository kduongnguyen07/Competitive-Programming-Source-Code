#include <bits/stdc++.h>
#define SZ(x) ((int)(x).size())
using namespace std;
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while (cin >> n) {
        multiset<int> all;
        while (n--) {
            int x; cin >> x;
            if (all.count(-x)) all.erase(all.find(-x));
            else all.insert(x);
        }
        assert(SZ(all) == 1);
        cout << -(*all.begin()) << endl;
    }
    return 0;
}

