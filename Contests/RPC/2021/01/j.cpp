#include <bits/stdc++.h>
using namespace std;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i, a, b) for (ll i = a; i < b; i++)
#define ft first
#define sd second
#define sz size()
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
typedef unsigned long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
//cout << fixed << setprecision(15) <<x<<endl;

const ll MAX = 1e6;
ll sum[MAX + 10];
ll dp[MAX + 20];
void suma()
{
    forn(i, 1, MAX + 1)
    {
        sum[i - 1] = ((i * (i + 1)) / 2);
    }
    dp[0] = sum[0];
    forn(i, 1, MAX)
    {
        dp[i] = dp[i - 1] + sum[i];
    }
}
int main()
{
    suma();
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        cout << dp[n - 1] << endl;
    }
    return 0;
}

