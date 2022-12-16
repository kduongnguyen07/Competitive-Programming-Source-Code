#include <iostream>
#include <cstdio>

using namespace std;
const int maxh = 20;
const int maxn = 1<<maxh;
int n;
int a[maxn+1];
int sum[maxn*5],l[maxn*5],r[maxn*5],vt[maxn+1];
int cnt[3];
void initIT(int i,int x,int y)
{
	l[i] = x;
	r[i] = y;
	if (x==y)
	{
		sum[i] = a[x];
		vt[x] = i;
	}
	else
	{
		int m=(x+y)>>1;
		initIT(i<<1,x,m);
		initIT((i<<1)|1,m+1,y);
		sum[i] = sum[i<<1] + sum[(i<<1)|1];
	}
}

void hai(int i)
{
	if (l[i]!=r[i])
	{
		if (sum[(i<<1)]>=sum[(i<<1)|1])
			hai(i<<1);
		else
			hai((i<<1)|1);
		sum[i] = sum[i<<1] + sum[(i<<1)|1];
	}
	else
	{
		cout << l[i] << ' ';
		sum[i] = 0;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	//freopen("input.001","r",stdin);
	//freopen("output.001","w",stdout);
	cin >> n;
	n=(1<<n);
	
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		if (a[i]>2 or a[i]<1)
		{
			cout << 0;
			return 0;
		}
		cnt[a[i]]++;
	}
	
	if (cnt[2]>1)
	{
		cout << 0;
		return 0;
	}
	
	cout << n <<endl;
	
	initIT(1,1,n);
	for (int i=1; i<=n; i++)
		hai(1);
	
	return 0;
}
