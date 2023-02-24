#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i)
                cin >> a[i];

        sort(a.begin(), a.end());

        if (a[0] + a[1] <= a[n - 1])
                cout << "CO";
        else
                cout << "KHONG";
        cout << "\n";

        return 0;
}
