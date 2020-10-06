#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(int i=a;i<=b;i++)
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
//cout << fixed << setprecision(12) <<x<<endl;

int main(){
fastIO;
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
#endif

short b=0,r=0,i=0;
cin >> b >> r;
short copia=r;
int pos[r];
vector<pair<int,int>> vec;
while(r--){
    int h=0,v=0,c=0;
    cin >> h >> v >> c;
    vec.push_back({c,v});
    pos[i]=h;
    i++;
}
sort(all(vec));
int ans=0,may=-1;;
for(auto &x:vec){
    if(x.sd>may){
        may=x.sd;
    }
    for(int j=0;j<copia;j++){
        if(x.ft==pos[j]){
            ans+=x.sd;
            break;
        }
    }
}
if(may<ans)
cout<<ans<<endl;
else cout<<may<<endl;
}

