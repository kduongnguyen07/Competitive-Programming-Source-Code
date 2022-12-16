#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        cin>>a[i];
    int maxA = *max_element(a.begin(), a.end());
    vector<int> cnt(maxA+1, 0);
    long long ans = 0;
    int l = 0;
    bool isGood = true;
    for(int r = 0; r < n; ++r) {
        ++cnt[a[r]];
        if (cnt[a[r]] > 2)
            isGood = false;
        while (!isGood) {
            if (cnt[a[l]] > 2)
                isGood = true;
            --cnt[a[l]];
            ++l;
        }
        ans += r-l+1;
    }
    cout<<ans;

    return 0;
}
