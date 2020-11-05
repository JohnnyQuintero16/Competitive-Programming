/**
fenwick tree 
https://vjudge.net/contest/404803#problem/B
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

const int MAX = 2e6;
ll bit[MAX + 1];
ll N;

void add(ll k, ll val)
{
    for (; k <= N; k += k&-k) bit[k] += val;
}

ll rsq(ll k)
{
    ll sum = 0;
    for (; k >= 1; k -= k&-k){
            sum += bit[k];
    }
    return sum;
}

ll rsq(ll i, ll j)
{
    return rsq(j) - rsq(i-1);
}

vector<string> split(const string &s/*, char c*/)
{
    vector<string> v;
    stringstream ss(s);
    string sub;
    while (ss >> sub) v.pb(sub);
    //while (getline(ss, sub, c)) v.pb(sub);
    return v;
}
int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    ll index = 0;
    while(cin >> N)
    {
        if(N == 0) break;
        memset(bit,0,sizeof(bit));
        forn(i,1,N+1){
            ll x = 0;
            cin >> x;
            add(i,x);
        }
        ++index;
        if(index != 1) cout << endl;
        cout << "Case " << index <<":" << endl;
        string s;
        cin.ignore();
        while(getline(cin, s))
        {
            if(s == "END") break;
            vector<string> v = split(s);
            if(v[0] == "M")
            {
                cout << rsq(stol(v[1]), stol(v[2])) << endl;
            }
            else
            {
                ll id = stol(v[1]), valor = stol(v[2]);
                ll sum = rsq(id,id);
                add(id,valor-sum);
            }
        }
    }
}

