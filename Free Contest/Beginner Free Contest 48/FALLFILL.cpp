#include <iostream>
#include <vector>
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int n, pos = 0; cin >> n;
    long long h = -1, sum = 0;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        if (arr[i] > h) {
            pos = i;
            h = arr[i];
        }
    }
    long long a, b, c, f; cin >> a >> b >> c >> f;

    long long power = a * h + b * n + c * h;

    h = 0;
    for (int i = 0; i < pos; ++i) {
        if (h > arr[i]) sum += h - arr[i];
        else h = arr[i];
    }

    h = 0;
    for (int i = n - 1; i > pos; --i) {
        if (h > arr[i]) sum += h - arr[i];
        else h = arr[i];
    }

    sum *= f;
    cout << power << ' ' << sum;

    return 0;
}
