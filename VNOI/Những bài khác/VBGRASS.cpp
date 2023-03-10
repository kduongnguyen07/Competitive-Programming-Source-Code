#include "bits/stdc++.h"
using namespace std;
#define int long long
int32_t main() {
    ios::sync_with_stdio(0);
    int nRow, nCol;
    while (cin >> nRow >> nCol) {
        vector<string> a(nRow);
        for (auto& s : a) cin >> s;

        int res = 0;
        for (int i = 0; i < nRow; i++) {
            for (int j = 0; j < nCol; j++) {
                if (a[i][j] == '#') {
                    if (
                            (i == 0 || a[i-1][j] == '.')
                            && (j == 0 || a[i][j-1] == '.')) {
                        res++;
                    }
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
