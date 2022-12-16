#include <bits/stdc++.h>
using namespace std;
void dapan(int n,int k)
{
    vector <int> factor;
	for (int i=1; i<=sqrt(n); i++)
	{
		if (n%i == 0)
		{   if (n/i == i)
            {
                factor.push_back(i);
            }

			else
            {
                factor.push_back(i);
                factor.push_back(n/i);
            }
		}
	}
sort(factor.begin(),factor.end());
if (k>factor.size()){
    cout<<-1<<endl;
}
else
cout<<factor[k-1]<<endl;
}
int main()
{   int n;cin>>n;
    for (int i=0;i<n;i++){
    int u,k;cin>>u>>k;
    dapan(u,k);
    }
}
