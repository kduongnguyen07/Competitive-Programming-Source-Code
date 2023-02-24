#include <bits/stdc++.h>

const int maxN = 1005;

char s[maxN][maxN];
int m, n, q, a[maxN][maxN], b[maxN][maxN], sum[maxN][maxN];

int Calc(int x1, int y1, int x2, int y2) {
    return sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1];
}

int main() {
    scanf("%d%d%d", &m, &n, &q);
    for(int i = 0; i < m; ++i)
        scanf("%s", s[i]);

    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j) a[i][j] = (s[i-1][j-1] == '*');

    for(int i = 1; i < m; ++i)
        for(int j = 1; j < n; ++j) b[i][j] = a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];

    for(int i = 1; i < m; ++i)
        for(int j = 1; j < n; ++j) sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+(b[i][j]%2);

    for(int i = 1; i <= q; ++i) {
        int x1, y1, x2, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        puts((Calc(x1, y1, x2-1, y2-1) == 0) ? "YES" : "NO");
    }
}
