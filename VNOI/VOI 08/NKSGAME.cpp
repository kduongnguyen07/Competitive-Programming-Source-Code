#include <bits/stdc++.h>

using namespace std;
int n;
int bSearch(int * a, int x){
    if (x < a[0]) return a[0];
    if (x > a[n-1]) return a[n-1];
    int l = 0, h = n-1;
    while (l<=h){
        int mid = l + (h - l)/2;
        if (a[mid] == x) return a[mid];
        if (a[mid] < x) l = mid + 1;
        else h = mid - 1;
    }
    if (abs(a[l]- x) <= abs(a[h]-x)) return a[l];
    return a[h];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    int * b = new int [n];
    int * c = new int [n];
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    for (int i = 0; i < n; i++){
        cin >> c[i];
    }
    sort(b, b+n);
    int min = INT_MAX;
    for (int i = 0; i < n; i++){
        int t = bSearch(b, -c[i]);
        int k = abs(t + c[i]);
        if (k == 0) {
            cout << 0 << endl;
            return 0;
        }
        if (min > k) min = k;
    }
    cout << min << endl;
    delete[]b;
    delete[]c;
    return 0;
}
