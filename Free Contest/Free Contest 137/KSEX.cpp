#include<bits/stdc++.h>
#define N 100006
#define pb push_back
#define int long long
using namespace std;

int n, q;
vector<int> a;

bool check(int mid, int x){
    if(mid < x) return false;
    int moc = mid - x;
    int res = upper_bound(a.begin(), a.end(), mid) - a.begin();
    if (res == moc) return true;
    else if(res > moc) return false;
    else return true;
}

int chop(int x){
    int r = 1e18 * 3;
    int l = 0;
    while(r - l > 1){
        int mid = (r + l)/2;
        if(mid < x){
            l = mid;
        }
        if(check(mid, x)) r = mid;
        else l = mid;
    }
    return r;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        int u; cin >> u;
        a.pb(u);
    }
    sort(a.begin(), a.end());
    while(q--){
        int k;
        cin >> k;
        cout << chop(k) << "\n";
    }
}
