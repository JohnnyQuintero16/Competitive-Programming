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
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<char, char> pcc;
typedef pair<double, double> pdd;
typedef pair<long long, long long> pll;
//cout << fixed << setprecision(15) <<x<<endl;


int main()
{
    fastIO;
    int t;
    cin >> t;
    while(t--){
        int p = 0, e = 0;
        cin >> p >> e;
        if((p-e) >= 10){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
} //g++ -std=c++17 main.cpp -o main && ./main < in.txt
