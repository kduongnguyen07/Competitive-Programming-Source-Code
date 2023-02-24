#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 0; i < n; ++i){
        int q;cin>>q;
        v.push_back(q);
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        vector<int> b = v;
        b.erase(b.begin() + i);
        int temp = 0;
        for(int j = 1; j < b.size(); ++j)
            temp = max(temp, b[j] - b[j-1]);
        ans = max(ans, temp);
    }
    cout << ans;
    return 0;
}