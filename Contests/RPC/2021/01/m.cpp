#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i, a, b) for (int i = a; i < b; i++)
#define ft first
#define sd second
#define sz size()
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
//cout << fixed << setprecision(15) <<x<<endl;


 ll MOD = 2147483647;

int x, y;
/// O(log(max(a, b)))
int euclid(int a, int b) {
    if(b == 0) { x = 1; y = 0; return a; }
    int d = euclid(b, a%b);
    int aux = x;
    x = y;
    y = aux - a/b*y;
    return d;
}
int invmod(int a, int m) {
    int d = euclid(a, m);
    if (d > 1) return -1;
    return (x % m + m) % m;
}

ll expmod(ll b, ll e, ll m) {
    ll ans = 1;
    while (e) {
        if (e&1) ans = (1ll*ans*b) % m;
        b = (1ll*b*b) % m;
        e /= 2;
    }
    return ans;
}
int main()
{
    fastIO;
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        ll term1 = expmod(n%MOD, 3 ,MOD);
        ll term2 = (3* (expmod(n%MOD,2,MOD)));
        ll term3 = (2* n);
        cout << (((term1%MOD + term2%MOD)%MOD + term3%MOD)%MOD * invmod(6,MOD))%MOD << endl;
    }
    return 0;
} //g++ -std=c++17 main.cpp -o main && ./main < in.txt

