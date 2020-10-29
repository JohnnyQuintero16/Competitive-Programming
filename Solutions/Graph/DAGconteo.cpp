/**
    Ejercicio DAG, Conteo de caminos
    https://vjudge.net/contest/403593#problem/B
**/
#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(ll i=a;i<b;i++)
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

const int MAX = 1e7;
vector<ll> g[MAX];
ll dp[MAX]; ///cnt de caminos
ll n, m;

ll f(ll u)
{
    if(g[u].sz == 0) return 1;
    if(dp[u] != -1) return dp[u];
    ll ans = 0;
    for(auto &v: g[u])
    {
        ans += f(v);
    }
    dp[u] = ans;
    return dp[u];
}
void init()
{
    forn(i,0,n)
    {
        g[i].clear();
    }
}
int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    bool flag = 0;
    while(cin >> n)
    {
        if(flag) cout<<endl;
        else flag = 1;
        forn(u,0,n)
        {
            cin >> m;
            forn(j, 0, m)
            {
                ll v;
                cin >> v;
                g[u].pb(v);
            }
        }
        memset(dp,-1,sizeof(dp));
        cout<<f(0)<<endl;
        init();
    }

}

