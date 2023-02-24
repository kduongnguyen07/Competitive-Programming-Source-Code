#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int n, m, k, ans[MAXN][MAXN];
char h[MAXN][MAXN], v[MAXN][MAXN];

void subtask1() {
    int cnt = 0, tot = (n-1)*m + n*(m-1);
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m-1; ++j)
            if (h[i][j] == 'E')
                ++cnt;
    for(int i = 0; i < n-1; ++i)
        for(int j = 0; j < m; ++j)
            if (v[i][j] == 'E')
                ++cnt;

    if (4*cnt >= 3*tot) {
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j)
                printf("%d ", 1);
            puts("");
        }
    } else
        puts("-1");
}

void subtask3() {
    if (n*(m-1) > (n-1)*m) {
        for(int i = 0; i < n; ++i) {
            ans[i][0] = 0;
            for(int j = 1; j < m; ++j)
                ans[i][j] = ans[i][j-1]^(h[i][j-1] == 'N');

            if (i > 0) {
                int cnt = 0;
                for(int j = 0; j < m; ++j)
                    cnt += ((ans[i][j]^ans[i-1][j]) == (v[i-1][j] == 'N'));

                if (2*cnt < m) {
                    for(int j = 0; j < m; ++j)
                        ans[i][j] ^= 1;
                }
            }
        }
    } else {
        for(int j = 0; j < m; ++j) {
            ans[0][j] = 0;
            for(int i = 1; i < n; ++i)
                ans[i][j] = ans[i-1][j]^(v[i-1][j] == 'N');

            if (j > 0) {
                int cnt = 0;
                for(int i = 0; i < n; ++i)
                    cnt += ((ans[i][j]^ans[i][j-1]) == (h[i][j-1] == 'N'));

                if (2*cnt < n) {
                    for(int i = 0; i < n; ++i)
                        ans[i][j] ^= 1;
                }
            }
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            printf("%d ", ans[i][j]+1);
        puts("");
    }
}

int main () {
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 0; i < n; ++i)
        scanf("%s", h[i]);
    for(int i = 0; i < n-1; ++i)
        scanf("%s", v[i]);

    if (k == 1)
        subtask1();
    else
        subtask3();

    return 0;
}
