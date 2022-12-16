#include <bits/stdc++.h>

using namespace std;

const long long inf = (1LL << 60);
const int maxn = 510;

// fast IO
template <typename T> inline void read(T &x)
{
	x = 0;
	char c;
	bool isNegative = false;
	while (!isdigit(c =  getchar()))
		if (c == '-') isNegative = !isNegative;
	do x = x * 10 + c - 48; while (isdigit(c = getchar()));
	if (isNegative) x = -x;
}

template<typename T, typename... Args> void read(T &x, Args&... args) 
{
    read(x);
    read(args...);
}

template <typename T> void Write(T x)
{
	if (x > 9) Write(x/10);
	putchar(x%10+48);
}

template <typename T> void write(T x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	Write(x);
}

class DinicFlow {
private:
    vector<int> dist, head, work;
    vector<long long> point, flow, capa, next;
    int n, m;

    bool bfs(int s, int t) {
        for(int i = 1; i <= n; i++) dist[i] = -1;
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int i = head[u]; i >= 0; i = next[i])
                if (flow[i] < capa[i] && dist[point[i]] < 0) {
                    dist[point[i]] = dist[u] + 1;
                    q.push(point[i]);
                }
        }
        return dist[t] >= 0;
    }

    long long dfs(int s, int t, long long f) {
        if (s == t) return f;
        for (int &i = work[s]; i >= 0; i = next[i])
            if (flow[i] < capa[i] && dist[point[i]] == dist[s] + 1) {
                long long d = dfs(point[i], t, min(f, capa[i] - flow[i]));
                if (d > 0) {
                    flow[i] += d;
                    flow[i ^ 1] -= d;
                    return d;
                }
            }
        return 0;
    }

public:
    DinicFlow(int n = 0) {
        this->n = n;
        this->m = 0;
        dist.assign(n + 7, 0);
        head.assign(n + 7, -1);
        work.assign(n + 7, 0);
    }

    void addEdge(int u, int v, long long c1, long long c2 = 0) {
        point.push_back(v);
        capa.push_back(c1);
        flow.push_back(0);
        next.push_back(head[u]);
        head[u] = m++;
        point.push_back(u);
        capa.push_back(c2);
        flow.push_back(0);
        next.push_back(head[v]);
        head[v] = m++;
    }

    long long maxFlow(int s, int t) {
        long long totFlow = 0;
        while (bfs(s, t)) {
            for(int i = 1;  i <= n; i++) work[i] = head[i];
            while (true) {
                long long d = dfs(s, t, inf);
                if (d == 0) break;
                totFlow += d;
            }
        }
        return totFlow;
    }
};

int n;
int a[maxn][maxn], w[maxn];
int id[maxn][maxn];

namespace BurteForce
{
    int m;
    vector < pair <int, int> > matchs;
    bool ok[maxn];

    void update()
    {
        int best = 0;
        for(int i = 1; i <= n; i++)
            best = max(best, w[i]);
        for(int i = 1; i <= n; i++)
            if (best == w[i]) ok[i] = true;
    }

    void Try(int i)
    {
        for(int j = 0; j < 2; j++)
        {
            if (j) w[matchs[i].second]++;
            else w[matchs[i].first]++;
            if (i < m -1) Try(i + 1);
            else update();
            if (j) w[matchs[i].second]--;
            else w[matchs[i].first]--;
        }
    }

    void solve()
    {
        matchs.clear();
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                for(int k = 0; k < a[i][j]; k++) matchs.push_back(make_pair(i, j)); 
        m = matchs.size();
        assert(m <= 25);
        for(int i = 1; i <= n; i++) ok[i] = false;
        if (m == 0)
            update();
        else Try(0);
        vector <int> res;
        for(int i = 1; i <= n; i++) 
            if (ok[i]) res.push_back(i);
        cout << (int)res.size();
        for(int x : res)
            cout << ' ' << x;
    }
};

void readInput()
{
    read(n);
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= n; j++) read(a[i][j]);
    for(int i = 1; i <= n; i++) read(w[i]);
}

namespace FlowSolution
{
    int vertexs, vs, vt;
    int id[maxn][maxn];

    void build(int u)
    {
        vertexs = n + 2;
        vs = n + 1, vt = n + 2;
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                if (a[i][j] && i != u && j != u) id[i][j] = ++vertexs;
                else id[i][j] = 0;
    }

    bool canWin(int u)
    {
        build(u);
        long long wins = w[u];
        for(int i = 1; i <= n; i++) wins += a[u][i];
        DinicFlow dinicFlow(vertexs);
        for(int i = 1; i <= n; i++)
            if (w[i] > wins) return false;
        long long sum = 0;
        for(int i = 1; i <= n; i++)
            for(int j = i + 1; j <= n; j++)
                if (id[i][j])
                {
                    dinicFlow.addEdge(vs, id[i][j], a[i][j]);
                    dinicFlow.addEdge(id[i][j], i, a[i][j]);
                    dinicFlow.addEdge(id[i][j], j, a[i][j]);
                    sum += a[i][j];
                }
        for(int i = 1; i <= n; i++)
            if (i != u)
                dinicFlow.addEdge(i, vt, wins - w[i]);
        return (sum == dinicFlow.maxFlow(vs, vt));
    }

    void solve()
    {
        vector <int> res;
        for(int i = 1; i <= n; i++)
            if (canWin(i)) res.push_back(i);
        cout << (int) res.size();
        for(int u : res) cout << ' ' << u;
    }
};


void solve()
{
    FlowSolution::solve();
}

int main()
{   
    int nTest;
    read(nTest);
    while (nTest--)
    {
        readInput();
        solve();
        if (nTest) cout << '\n';
    }    
}
