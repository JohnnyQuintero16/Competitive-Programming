#include <bits/stdc++.h>
using namespace std;
///https://trainingcenter.cloud.ufps.edu.co/problemas/378/detalle/en
/// Coeficiente binomial con modificacion de multiplicacion e inverso modular
const long long M = 1000000007;

long long mulmod(long long a, long long b, long long m) {
    long long r = a*b-(long long)((long double)a*b/m+.5)*m;
    return r < 0 ? r+m : r;
}

int expmod(int b, int e, int m) {
    int ans = 1;
    while (e) {
        if (e&1) ans = (1ll*ans*b) % m;
        b = (1ll*b*b) % m;
        e /= 2;
    }
    return ans;
}
int invmod(int a, int m) {
    return expmod(a, m-2, m);
}

long long ncr(long long n, long long r) {
    if (r < 0 || n < r) return 0;
    r = min(r, n-r);
    long long ans = 1;
    for (long long i = 1; i <= r; i++) {
        ans = mulmod(ans, (n-i+1), M) * invmod(i,M);
    }
    return ans%M;
}
int main() {
	// your code goes here
	int n = 0, m = 0;
	while(cin >> n >> m){
	if(n == 0 && m == 0) break;
	cout << ncr(n,m) << endl;
	}
	return 0;
}
