#include <bits/stdc++.h>
using namespace std;
int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    string s;cin>>s;
    int tong=0;
    int a;cin>>a;
    for (auto x:s)
    {
        if ((x-'a'+a)<26)
        tong+=(x-'a'+a);
        else if ((x-'a'+a)>=26)
        {
            tong+=(x-'a'+a)-26;
        }
    }
    cout<<tong;
    return 0;
}
