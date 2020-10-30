/**
    Ejercicio Aplicando Segment Tree --> max
    https://vjudge.net/contest/403593#problem
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

typedef ll T; //tipo de dato del segtree
struct segtree {
    vector<T> st;//, lazy;
    ll n; T neutro = -1; // "infinito"
    segtree(const vector<ll> &v) {
        n = v.size();
        st.assign(n*4, 0);
        //lazy.assign(n*4, neutro);
        build(1, 0, n-1, v);
    }
    void build(ll p, ll L, ll R, const vector<ll> &v) {
        if (L == R) st[p] = v[L];
        else {
            ll m = (L+R)/2, l = p*2, r = l+1;
            build(l, L, m, v);
            build(r, m+1, R, v);
            st[p] = max(st[l], st[r]);
        }
    }
    T query(ll i, ll j) { return query(1, 0, n-1, i, j); }
    void upd(ll i, ll j, T val) { upd(1, 0, n-1, i, j, val); }

    T query(ll p, ll L, ll R, ll i, ll j) {
        if (i > R || j < L) return neutro;
        //propagate(p, L, R, lazy[p]);
        if (i <= L && j >= R) return st[p];
        ll m = (L+R)/2, l = p*2, r = l+1;
        T lf = query(l, L, m, i, j);
        T rg = query(r, m+1, R, i, j);
        return max(lf, rg);
    }

    void upd(ll p, ll L, ll R, ll i, ll j, T val) {
        if (i > R || j < L) return;
        //propagate(p, L, R, lazy[p]);
        if (i <= L && j >= R) st[p] = val;//propagate(p, L, R, val);
        else {
            ll m = (L+R)/2, l = p*2, r = l+1;
            upd(l, L, m, i, j, val);
            upd(r, m+1, R, i, j, val);
            st[p] = max(st[l], st[r]);
        }
    }
};

int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    ll n;
    cin >> n;
    ll alturas[n];
    ll belleza[n];
    forn(i,0,n) cin >> alturas[i];
    forn(i,0,n) cin >> belleza[i];
    vector<ll> v(n,0);
    segtree tree(v);
    ll ans = 0, sum = 0;
    forn(i,0,n){
        ll consul = tree.query(0,alturas[i]-1); /// rango de 0 a la altura i
        ll act = tree.query(alturas[i],alturas[i]);
        //cout << consul << " " << act << endl;
        ll sum = belleza[i] + consul;
        if(act < sum){
            tree.upd(alturas[i], alturas[i], sum);
            ans = max(ans, sum);
            //cout << ans << endl;
        }
    }
    cout << ans << endl;
}

