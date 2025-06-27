#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define test int t;cin >> t;for(int z=0;z<t;z++)
#define f(start,end,name) for(int name = (start);name < (end);name++)
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define nl '\n'
#define setIO(inputFile, outputFile) freopen(inputFile, "r", stdin); freopen(outputFile, "w", stdout)

ll modpow(ll a,ll b, ll m){
    if(b==0) return 1%m;
    else if(a==0) return 0;
    ll u = modpow(a,b/2,m);
    __int128_t var = (__int128_t(u)*u)%m;
    if(b%2==1) return (ll)((var*a)%m);
    else return (ll)var;
}

ll modinv(ll a, ll m){
    return a <= 1? a : m - ((ll(m/a) * modinv(m%a,m))%m) ;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

//setIO("sumdiv.in","sumdiv.out");

ll m = 1e9+7;
ll a,b;
map<ll,int> factors; 
cin >> a >> b;

for(ll x=2;x*x<=a;x++){
    while(a%x==0){
        factors[x]++;
        a /= x;
    }
}
if(a>1) factors[a]++;
ll s=1;
if(b != 0){
    b = b%(m-1);
for(auto x:factors){
    ll tmp = ((b*x.second) + 1)%(m-1);
    tmp = modpow(x.first,tmp,m)-1;
    tmp = tmp<0?tmp+m:tmp;
    ll inv = modinv(x.first%m-1,m);
    cout << inv << nl;
    inv = inv<0?inv+m:inv;
    __int128_t r = __int128_t(tmp)*inv*s % m;
    s = (ll)r;  
}}

cout <<s;

}