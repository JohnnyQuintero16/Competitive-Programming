/**
    https://vjudge.net/contest/403593#problem/D
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

const int MAX = 1e6;
vector<int> g[MAX + 1];
int cnt[MAX];
int n, m;

int reco(int u)
{
    cnt[u] = 1;
    int ans = 0;
    for(auto &v: g[u])
    {
        if(cnt[v] == 0)
        {
            ans+= reco(v);
            cnt[u]+=cnt[v];
            if(cnt[v]%2 == 0)
            {
                ans++;
            }
        }
    }
    return ans;
}
int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    cin >> n >> m;
    forn(i,1,m+1)
    {
        short u = 0,v = 0;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    memset(cnt, 0, sizeof(cnt));
    cout<<reco(1)<<endl;
}

