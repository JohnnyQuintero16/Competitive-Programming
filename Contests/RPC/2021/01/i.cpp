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
    ll a = 0, b = 0;
    while (cin >> a >> b)
    {
        if (a == 0 && b == 0)
            break;
        if (b == 0)
        {
            cout << a << endl;
            continue;
        }
        else if (b == 1)
        {
            cout << a << "i" << endl;
            continue;
        }
        else if (b == 2)
        {
            cout << (a * (-1)) << endl;
            continue;
        }
        else if (b == 3)
        {
            cout << (a * (-1)) << "i" << endl;
            continue;
        }
        else if (b == 4)
        {
            cout << a << endl;
            continue;
        }
        else
        {
            int res = b % 4;
            if (res == 0)
            {
                cout << a << endl;
                continue;
            }
            else
            {
                if (res == 1)
                {
                    cout << a << "i" << endl;
                    continue;
                }
                else if (res == 2)
                {
                    cout << (a * (-1)) << endl;
                    continue;
                }
                else if (res == 3)
                {
                    cout << (a * (-1)) << "i" << endl;
                    continue;
                }
            }
        }
    }

    return 0;
} //g++ -std=c++17 main.cpp -o main && ./main < in.txt
