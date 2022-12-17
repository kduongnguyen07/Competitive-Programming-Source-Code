#include <bits/stdc++.h>
using namespace std;
int n, m, SUM1[200007], SUM2[200007];
int main() {
    cin>>n>>m;
    for(int i = 0; i < n; ++i) {
        int l, r, s;
        cin>>l>>r>>s;
        SUM1[r] += s;
        SUM2[l] += s;
    }
    for(int i = 2; i <= m; ++i)
        SUM1[i] += SUM1[i-1];
    for(int i = m-1; i >= 1; --i)
        SUM2[i] += SUM2[i+1];
    int ans = 0;
    for(int i = 1; i <= m; ++i)
    {  
        ans = max(ans, SUM1[i-1] + SUM2[i+1]);
    }
    cout<<ans;
    return 0;
}