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


const int MAX = 1e5;
vector<int> g[MAX];
int low[MAX], pre[MAX], comp[MAX], c,cSCC,N,M;
stack<int> st;
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
            low[x] = 1e9;
            comp[x] = cSCC;
            if(x == u) break;
        }
        cSCC++;
    }
}
void init()
{
    c=0;
    cSCC = 0;
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

    while(cin >> N >> M)
    {
        init();
        int x, u, v;
        forn(i,0,M)
        {
            cin>>x;
            if(x==1)
            {
                cin>>u>>v;
                u--;
                v--;
                g[u].pb(v);
            }
            else
            {
                cin>>u>>v;
                u--;
                v--;
                int aux = u;
                g[u].pb(v);
                forn(i,2,x)
                {
                    u = v;
                    cin >> v;
                    v--;
                    g[u].pb(v);
                }
                g[v].pb(aux);
            }
        }
        forn(i,0,N)
        {
            if(pre[i] == -1)
            {
                dfs(i);
            }
        }
        if(cSCC == 1)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }

}

