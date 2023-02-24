#include <bits/stdc++.h>
using namespace std;
#define fi(i, a, b) for(int i = a; i <= b; i++)
#define ll long long
string s;
char x,y;
ll res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    getline(cin,s);
    cin>>x>>y;
    ll dem=0;
    fi(i,0,s.length()-1)
    {
        if (s[i]==y) res+=dem;
        if (s[i]==x) dem++;

    }
    cout<<res;
    return 0;
}
