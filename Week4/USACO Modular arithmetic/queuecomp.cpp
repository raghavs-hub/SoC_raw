#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define test int t;cin >> t;for(int z=0;z<t;z++)
#define f(start,end,name) for(int name = (start);name < (end);name++)
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define nl '\n'
#define setIO(inputFile, outputFile) freopen(inputFile, 'r', stdin); freopen(outputFile, 'w', stdout)


ll modinv(ll a, ll m){
    return a <= 1? a : m - ((ll(m/a) * modinv(m%a,m))%m) ;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int q; cin >> q;
ll m = 998244353;
int s=0;
//int end =-1;
int x;
vector<pair<ll,ll>> funcs;
ll A = 1,B=0;
f(0,q,i){
    cin >> x;
    if(x==0){
        ll a,b;
        cin >> a >> b;
        funcs.push_back(MP(a,b));
        A = A*a%m;
        B = (a*B%m + b)%m;
        //end++;
    } else if(x == 1){
        ll ainv = modinv(funcs[s].first,m);
        ll binv = ainv*funcs[s].second%m;
        B = B - (A*binv)%m;
        B = B<0 ? m+B%m : B%m;
        A = A*ainv%m;
        s++;
    } else if(x == 2){
        ll var; cin >> var;
        var = ((A*var)%m +B)%m;
        cout << var << nl;
    }
}

}