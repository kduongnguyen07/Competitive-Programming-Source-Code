#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(); cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    cout << 1;
    for(int i = 2, j = n; i < j; ++i, --j)
        cout << ' ' << j << ' ' << i;
    if (n % 2 == 0) cout << ' ' << (n+2) / 2;
    cout << '\n';
}