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

int main()
{
    fastIO;
    ll m = 0, n = 0;
    while (cin >> m >> n)
    {
        if (m == 0 && n == 0)
            break;
        vector<ll> A(m), B(n), Aux(n + m);
        forn(i, 0, m)
        {
            cin >> A[i];
        }
        forn(i, 0, n)
        {
            cin >> B[i];
        }
        vector<ll>::iterator it;
        sort(all(A));
        sort(all(B));
        it = set_difference(all(A), all(B), Aux.begin());
        cout << it - Aux.begin() << " ";
        it = set_intersection(all(A), all(B), Aux.begin());
        cout << it - Aux.begin() << " ";
        it = set_difference(all(B), all(A), Aux.begin());
        cout << it - Aux.begin() << " ";
        it = set_union(all(A), all(B), Aux.begin());
        cout << it - Aux.begin() << "";
        cout << endl;
        /*
            Operaciones de conuntos con funcion de c++
            para mas info: http://www.cplusplus.com/reference/algorithm/set_intersection/
        */
    }
    return 0;
} //g++ -std=c++17 main.cpp -o main && ./main < in.txt

