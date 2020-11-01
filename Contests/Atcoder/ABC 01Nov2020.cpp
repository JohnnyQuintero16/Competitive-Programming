/**

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


void A()
{
    int n;
    cin >> n;
    int arr[30+1];
    for(int i = 1; i<=30; i++)
    {
        arr[i] = 0;
        arr[i+1] = 1;
    }
    if(arr[n] == 1)
    {
        cout<<"White"<<endl;
    }
    else
    {
        cout<<"Black"<<endl;
    }
    //cout<<arr[n]<<endl;
}

void B()
{


}
int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif

}

