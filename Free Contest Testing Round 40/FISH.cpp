#include <bits/stdc++.h>

using namespace std;

const int MAXN = 405;
const long long oo = 1000000000000000007LL;

int N, M, A[MAXN][MAXN], X[MAXN], Y[MAXN];
long long d[MAXN][MAXN];

int main() {
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= N; ++i)
        scanf("%d", &X[i]);
    for(int i = 1; i <= M; ++i)
        scanf("%d", &Y[i]);
    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            scanf("%d", &A[i][j]);

    for(int i = 1; i <= N; ++i)
        for(int j = 1; j <= M; ++j)
            d[i][j] = d[i-1][j] + A[i][j];

    long long ans = 0;
    for(int i1 = 1; i1 <= N; ++i1) {
        for(int i2 = i1; i2 <= N; ++i2) {
            long long sum = 0, minP = oo;
            for(int j = 1; j <= M; ++j) {
                minP = min(minP, sum - 1LL*(X[i2]-X[i1])*Y[j]);
                sum += d[i2][j] - d[i1-1][j];
                ans = max(ans, sum - 1LL*(X[i2]-X[i1])*Y[j] - minP);
            }
        }
    }

    cout << ans;

    return 0;
}
