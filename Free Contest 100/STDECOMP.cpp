#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <map>
#define ii pair<int,int>
#define X first
#define Y second
using namespace std;
const int maxn = (int) 1e5; 
int n,m;

map<ii,int> M;
vector<ii> V[maxn+1];
vector<vector<int>> res;
vector<int> tmp;
bool visit[maxn+1];

void dfs(int x)
{
	visit[x] = true;
	for (auto it=V[x].begin(); it!=V[x].end(); it++)
	{
		int y = (*it).X;
		if (!visit[y] and M.count(ii(x,y)))
		{
			tmp.push_back(M[ii(x,y)]);
			M.erase(ii(x,y));
			M.erase(ii(y,x));
			dfs(y);
		}
	}
}
int main()
{
	cin >> n >> m;
	
	for (int i=1; i<=m; i++)
	{
		int x,y,w;
		cin >> x >> y >> w;
		V[x].push_back(ii(y,w));
		V[y].push_back(ii(x,w));
		M[ii(x,y)] = i;
		M[ii(y,x)] = i;
	}
	
	do
	{
		memset(visit,false,sizeof(visit));
		tmp.clear();
		dfs(1);
		if (tmp.size()==n-1)
			res.push_back(tmp);
		else
			break;
	}
	while (true);
	
	cout << res.size() << '\n';
	for (int i=0; i<res.size(); i++)
	{
		for (int j=0; j<n-1; j++)
			cout << res[i][j] << ' ';
		cout << '\n';
	}
	return 0;
}
