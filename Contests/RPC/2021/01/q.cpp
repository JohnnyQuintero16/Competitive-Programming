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

int main()
{

    int t = 0;
    cin >> t;
    while (t--)
    {
        int q = 0;
        cin >> q;
        stack<int> st;
        multiset<int> mt;
        while (q--)
        {
            int op = 0;
            cin >> op;
            if (op == 1)
            {
                int val = 0;
                cin >> val;
                mt.insert(val);
                st.push(val);
            }
            else if (op == 2)
            {
                if (st.empty())
                {
                    continue;
                }
                int tmp = st.top();
                st.pop();
                mt.erase(mt.find(tmp));
            }
            else
            {
                if (st.empty())
                {
                    cout << "Empty!" << endl;
                }
                else if (st.sz == 1)
                {
                    cout << 0 << endl;
                }
                else
                {
                    auto mi = mt.begin();
                    auto ma = mt.rbegin();
                    cout << abs(*ma - *mi) << endl;
                }
            }
        }
    }
    return 0;
}
