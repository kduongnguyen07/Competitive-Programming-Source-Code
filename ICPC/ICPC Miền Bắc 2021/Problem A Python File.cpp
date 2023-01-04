#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
string s;
cin>>s;
int len=s.length();
if((s[len-3]=='.')&&(s[len-2]=='p')&&(s[len-1]=='y')||(s[len-3]=='.')&&(s[len-2]=='p')&&(s[len-1]=='Y')||(s[len-3]=='.')&&(s[len-2]=='P')&&(s[len-1]=='y')||(s[len-3]=='.')&&(s[len-2]=='P')&&(s[len-1]=='Y'))
{
	cout<<"yes";
}
else cout<<"no";
return 0;
}
