#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; cin >> t;
    while (t--){
        string n; int k;
        cin >> n >> k;

        int sum = 0;
        bool f2 = false, f3 = false, g;
        
        for(char i : n){
            sum += (i - '0');
        }

        f2 = ((n.back() - '0') % 2 == 0);
        f3 = f2 & (sum % 3 == 0);

        g = (k == 1) || (k == 2 && f2) || (k == 3 && f3);

        if (g) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}