#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
 
const int MAX = 1001;
int ans[MAX];
 
int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
 
    int a=0,r=0,h=0,v=0,c=0;
    cin >> a >> r;
    for(int i=1;i<=a;i++) ans[i]=0;
    while(r--)
    {
        h = 0;
        v = 0;
        c = 0;
        cin >> h >> v >> c;
        int Vmax = -1,copiaH = h,i=c;
        while(copiaH--){
        	Vmax = max(Vmax,ans[i]);
        	i++;
        }
        int j = c;
        while(h--){
        	ans[j]=(Vmax+v);
        	j++;
        }
    }
    int rta = -1;
    for(int i=1;i<=a;i++)
    {
        rta = max(rta,ans[i]); //Busca el mayor en todo el arreglo.
        //cout<<ans[i]<<endl;
    }
    cout<<rta<<endl;
}

































    























