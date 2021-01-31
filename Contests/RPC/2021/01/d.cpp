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

const int MAX = 1e4 + 1;
ll fibo[MAX + 20];
const int MOD = 2147483647;
void fib()
{
    fibo[0] = 0;
    fibo[1] = 1;
    forn(i, 2, MAX)
    {
        fibo[i] = (fibo[i - 1] % MOD + fibo[i - 2] % MOD) % MOD;
    }
}
int main()
{
    fastIO;
    fib();
    ll t = 0;
    cin >> t;
    while (t--)
    {
        ll n = 0;
        cin >> n;
        bool flag = 0;
        forn(i, 0, MAX)
        {
            if (fibo[i] == n)
            {
                flag = 1;
            }
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
