#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(int i=a;i<b;i++)
#define ft first
#define sd second
#define sz size()
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<string,int> psi;
typedef pair<char,char> pcc;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
//cout << fixed << setprecision(15) <<x<<endl;

const int MAX = 1e6;
vector<int> g[MAX];
int pre[MAX], low[MAX];
int cntP, N, M;
vector<pii> puente;
void dfs(int u, int p = -1)
{
    low[u] = pre[u] = cntP++;
    for(auto &v:g[u])
    {
        if(v == p) continue;
        if(pre[v] == -1)
        {
            dfs(v,u);
            if(low[v] > pre[u])
            {
                puente.pb({min(u,v),max(u,v)});
            }
            low[u] = min(low[u],low[v]);
        }
        else if(pre[v] < pre[u])
        {
            low[u] =  min(low[u], pre[v]);
        }
    }
}

void init()
{
    cntP = 0;
    forn(i,0,N)
    {
        g[i].clear();
        pre[i] = -1;
        //low[i] = -1;
    }
    puente.clear();
}

int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    while(cin >> N >> M && N!=0 && M!=0)
    {
        init();
        forn(i,0,M)
        {
            int u = 0,v = 0;
            cin >> u >> v;
            g[u].pb(v);
            g[v].pb(u);
        }
        forn(i,0,N)
        {
            cntP = 0;
            if(pre[i] == -1)
            {
                dfs(i);
            }
        }
        sort(puente.begin(), puente.end());
        cout<<puente.sz;
        for(auto &x:puente)
        {
            cout<<" "<<x.ft<<" "<<x.sd;
        }
        cout<<endl;
    }
}
