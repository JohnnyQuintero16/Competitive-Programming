https://trainingcenter.cloud.ufps.edu.co/problemas/201/detalle/en#include<bits/stdc++.h>;
using namespace std;
//#define LOCAL
typedef long long ll;
#define fastIO ios::sync_with_stdio(0), cin.tie(0)

int main(){
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
     //freopen("out.txt", "w", stdout);
#else
 fastIO;
#endif
//***************************//**************************//******************************

int n;
while(cin>>n){
    vector<pair<int,int>> v;
    for(int i=n+1;i<=n*2;i++){
        int nu=i-n;
        int d=i*n;
        if(d%nu==0){
            v.push_back({d/nu,i});
        }
    }
    cout<<v.size()<<endl;
    for(auto &x:v){
        cout<<1<<"/"<<n<<" = "<<1<<"/"<<x.first<<" + "<<1<<"/"<<x.second<<endl;
    }
}
}
