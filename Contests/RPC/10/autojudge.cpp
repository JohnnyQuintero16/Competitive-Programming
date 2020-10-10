#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(int i=a;i<b;i++)
#define ft first
#define sd second
#define sz size()
#define pb push_back
bool Extension(string s, string ar)
{
    bool flag = 0;
    short i = 0;
    for(; i < s.sz; i++)
    {
        if(s[i]!=ar[i])
        {
            flag = 1;
        }
    }
    string extension = ar.substr(i,ar.sz);
    //cout<<extension<<endl;
    string exts[] = {".cpp", ".py", ".c", ".java"};
    bool aux = 1;
    for(int k = 0; k<4; k++)
    {
        if(exts[k]==extension)
        {
            aux = 0;
        }
    }
    return flag || aux;
}

int main()
{
    fastIO;
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    string nombre="",archivo="";
    cin>>nombre;
    cin.ignore();
    getline(cin,archivo);
    //Compile Error
    bool flagExtension = Extension(nombre,archivo);
    if(flagExtension)
    {
        cout<<"Compile Error"<<endl;
        return 0;
    }
    //Run-Time Error
    short r = 0, d = 0, e = 0;
    cin >> r >> d >> e;
    if(r != 0)
    {
        cout<<"Run-Time Error"<<endl;
        return 0;
    }
    //Time Limit Exceeded
    if(e>d)
    {
        cout<<"Time Limit Exceeded"<<endl;
        return 0;
    }
    /// Wrong Answer
    bool flagWA = 0;
    short ans = 0, copiaAns=0;
    cin >> ans; ///cant rta correctas
    copiaAns=ans;
    vector<string> ansCorrect; ///vector de ans correctas
    cin.ignore();
    while(copiaAns--)
    {
        string s;
        getline(cin,s);
        ansCorrect.pb(s);
    }
    short ansP = 0;
    cin >> ansP; ///cant de rta del user
    if(ans == ansP) ///si tiene la misma cant de rta del user y compiler
    {
        vector<string> ansProgra; ///vect de rta del user
        cin.ignore();
        while(ansP--)
        {
            string sP;
            getline(cin,sP);
            ansProgra.pb(sP);
        }

        bool flagAux = 0;
        auto y = ansProgra.begin();
        for(auto &x:ansCorrect)
        {
            string p = *(y);
            if(x!=p)
            {
                flagWA = true;
                break;
            }
            y++;
        }
    }
    else
    {
        flagWA = 1;
    }

    if(flagWA)
    {
        cout<<"Wrong Answer"<<endl;
        return 0;
    }
    cout<<"Correct"<<endl;
}


