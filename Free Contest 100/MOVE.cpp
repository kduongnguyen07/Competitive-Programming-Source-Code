#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, n, x1, y1, x2, y2;
    cin>>m>>n;
    cin>>x1>>y1;
    cin>>x2>>y2;
    int ans;
    if (abs(x1-x2)%2 == 1 || abs(y1-y2)%2 == 1)
        ans = -1;
    else
        ans = abs(x1-x2)/2 + abs(y1-y2)/2;
    cout<<ans;

    return 0;
}
