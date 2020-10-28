/**
  Subsecuencia Creciente mas larga
  esta en nlogn y  n.n
  https://vjudge.net/contest/403593#problem/F
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
int L[N], S[N], n;
vector<pair<pii,int>> datos;
bool cmp(pair<pii,int> &a, pair<pii,int> &b)
{
    if(a.ft.ft != b.ft.ft) return a.ft.ft > b.ft.ft;
    return a.ft.sd < b.ft.sd;
}

void LISNxN(){
    forn(i,0,n) L[i] = 1;
    forn(i,0,n){
        //cout<<datos[i].ft.sd<<" "<<" "<<datos[i].ft.ft<<" "<<datos[i].sd<<endl;
        forn(j,i+1,n){
            if(datos[i].ft.sd < datos[j].ft.sd && datos[i].ft.ft > datos[j].ft.ft){
                L[j] = max(L[j],L[i]+1);
            }
        }
    }
    int mx = 0;
    forn(i,0,n){
        //cout<<L[i]<<" ";
        mx = max(mx,L[i]);
    }
    cout<<mx<<endl;

    int id;
    for(int i = n-1; i >= 0; i--){
        if(L[i] == mx) id = i;
    }
    vector<int> ans;
    ans.pb(datos[id].sd);
    for(int j = id-1; j >= 0; j--){
        if((datos[id].ft.sd > datos[j].ft.sd) && (datos[id].ft.ft < datos[j].ft.ft) && L[j] == L[id]-1){
            ans.pb(datos[j].sd);
            id = j;
        }
    }
    reverse(all(ans));
    for(auto &x:ans){
        cout<<x+1<<endl;
    }
}
void LISNLOGN()
{
    forn(i,0,n)
    {
        L[i] = 1;
    }
    vector<int> I;
    I.pb(-inf);
    forn(i, 0, n)
    {
        int pos = lower_bound(I.begin(), I.end(), datos[i].ft.sd)-I.begin();
        //cout<<pos<<endl;
        if(pos == I.sz) I.pb(datos[i].ft.sd);
        else I[pos] = datos[i].ft.sd;
        L[i] = pos;
    }
    int mx = I.sz-1;
    int id;
    for(int i = n-1; i >= 0; i--){
        if(L[i] == mx) id = i;
    }
    vector<int> ans;
    ans.pb(datos[id].sd);
    for(int j = id-1; j >= 0; j--)
    {
//if((datos[id].ft.sd > datos[j].ft.sd) && (datos[id].ft.ft < datos[j].ft.ft) && L[j] == L[id]-1){
        if((datos[id].ft.sd > datos[j].ft.sd) && (datos[id].ft.ft < datos[j].ft.ft) && L[j] == L[id]-1)
        {
            ans.pb(datos[j].sd);
            id = j;
        }
    }
    cout<<mx<<endl;
    //cout<<ans.sz<<endl;
    reverse(all(ans));
    for(auto &x:ans)
    {
        cout<<x+1<<endl;
    }
}
int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

    int peso = 0, coeficiente = 0, i = 0;
    while(cin >> peso >> coeficiente)
    {
        datos.pb({{coeficiente,peso},i});
        i++;
    }
    sort(datos.begin(),datos.end(),cmp);
    n = datos.sz;
    LISNLOGN();
}

