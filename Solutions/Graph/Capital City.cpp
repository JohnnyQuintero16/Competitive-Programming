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


const int MAX = 1e6+5;
vector<int> g[MAX];
int low[MAX],pre[MAX],comp[MAX],N,M;
int SCC,c;
stack<int> st;
map<int,vector<int>> compo;













void dfs(int u)
{
    low[u] = pre[u] = c++;
    st.push(u);
    for(auto &v:g[u])
    {
        if(pre[v] == -1)
        {
            dfs(v);
        }
        low[u] = min(low[u],low[v]);
    }
    if(low[u] == pre[u])
    {
        while(1)
        {
            int x = st.top();
            st.pop();
            low[x] = 10000000;
            comp[x] = SCC;
            compo[SCC].pb(x+1);
            if(x == u) break;
        }
        SCC++;
    }
}
void init()
{
    c=0;
    forn(i,0,N+1)
    {
        g[i].clear();
        pre[i]=-1;
    }
}
int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    init();
    cin >> N >> M;
    forn(i,0,M)
    {
        int u,v;
        cin >> u >>v;
        u--;
        v--;
        g[u].pb(v);
    }
    memset(pre,-1,sizeof(pre));
    forn(u,0,N)
    {
        if(pre[u] == -1)
        {
            dfs(u);
        }
    }
    for(auto &x:compo)
    {
        //cout<<x.ft<<" --> "<<x.sd.sz;
        if(x.sd.sz>1)
        {
            cout<<x.sd.sz<<endl;
            sort(x.sd.begin(),x.sd.end());
            for(auto &y:x.sd)
            {
                cout<<y<<" ";
            }
        }
    }
}
