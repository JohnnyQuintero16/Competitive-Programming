/**
    Ejercicio de DAG (Grafos)
    https://vjudge.net/contest/403593#problem/E
    Ejemplo clasico de minimos y maximos
**/
#include <bits/stdc++.h>
using namespace std;
#define LOCAL
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

const int N = 1e6, inf = 1e9;
vector<int> g[N];
int n, c, m;
bitset<N> marked;
pii dp[N];
pii f(int u){
    if(u == n) return {marked[u],marked[u]};
    if(dp[u].ft != -1) return dp[u];
    dp[u].ft = inf, dp[u].sd = -inf;
    for(auto &v: g[u]){
        dp[u].ft = min(dp[u].ft, f(v).ft + marked[u]);
        dp[u].sd = max(dp[u].sd, f(v).sd + marked[u]);
    }
    return dp[u];
}

int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    cin >> n >> c >> m;
    int u, v;
    forn(i,0,c){
        cin >> u;
        marked[u] = 1;
    }
    forn(i,0,m){
        cin >> u >> v;
        g[u].pb(v);
    }
    memset(dp, -1, sizeof(dp));
    cout << f(1).ft << " " << f(1).sd << endl;

}

