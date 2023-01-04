#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
using namespace std;
using namespace __gnu_pbds;

template <typename T> using order_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
order_multiset<int> s;

signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int q; cin >> q;
    while (q--) {
        string ss; cin >> ss;
        if (ss[0] == 'I') {
            int x; cin >> x;
            s.insert(x);
        }
        else if (ss[0] == 'O') {
            int x; cin >> x;
            int c = s.order_of_key(x);
            auto it = s.find_by_order(c);
            s.erase(it);
        }
        else if (ss[0] == 'M') {
            int sz = s.size();
            //cout << sz << ' ';
            int res = *s.find_by_order(sz / 2) + *s.find_by_order((sz - 1) / 2);
            cout << res / 2;
            if (res & 1) cout << ".5";
            cout << '\n';
        }
    }
}
