#include <bits/stdc++.h>

using namespace std;

long long n;

int main() {
    cin >> n;

    long long ans = n;
    for(long long i = 1; i * i <= n; ++i) {
        if (n % i == 0)
            ans = min(ans, i + n/i - 2);
    }

    cout << ans << endl;

    return 0;
}
