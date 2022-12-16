#include <bits/stdc++.h>
using namespace std;
int main()
{
int n;cin>>n;
for (int i=0;i<n;i++)
    {
    long long check;
    cin>>check;
    if (check%4==2)
    {
        cout<<"impossible"<<endl;
    }
    if (check%4==1)
        {
            cout<<(check+1)/2<<" "<<(check-1)/2<<endl;
        }
    if (check%4==3)
        {
            cout<<(check+1)/2<<" "<<(check-1)/2<<endl;
        }
    if (check%4==0)
        {
            cout<<(check/4)+1<<" "<<(check/4)-1<<endl;
        }
    }
}
