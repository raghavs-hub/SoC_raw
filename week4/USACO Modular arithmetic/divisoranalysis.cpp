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
#define setIO(inputFile, outputFile) freopen(inputFile, 'r', stdin); freopen(outputFile, 'w', stdout)

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

ll m = 1e9+7;
int n; cin >> n;
map<int,ll> mp;
f(0,n,i){
    int x;ll k;
    cin >> x >> k;
    mp[x] = k;
}
bool issq = true;
ll it1 =1;
ll num = 1;
ll num1 = 1;
ll sum = 1;
ll pdt = 1;
int var=2;
for(auto x: mp){
    if(x.second%2 != 0) issq = false;
    __int128_t r = __int128_t(num) * (x.second+1) % m;
    num = (ll)r;
    if(var == 2 && x.second%2 != 0){
        r = __int128_t(num1) * ((x.second+1)/2) % (m-1);
        num1 = (ll)r;
        var = 0;
    } else{
    r = __int128_t(num1) * (x.second+1) % (m-1);
    num1 = (ll)r;}
    ll temp = modpow(ll(x.first),(1+x.second)%(m-1),m)-1;
    temp = temp<0 ? temp+m:temp;
    ll inv = modinv(ll(x.first-1),m);
    r = __int128_t(temp) * inv * sum % m;
    sum = (ll)r;
    r = __int128_t(it1) * modpow(x.first,x.second,m) % m;
    it1 = (ll)r;
}
ll it2=1;
if(issq){
    for(auto x: mp){
        __int128_t r = __int128_t(it2) * modpow(x.first,x.second/2,m) % m;
        it2 = (ll)r;
    }
    pdt = modpow(it2,num1,m);    
} else{
    pdt = modpow(it1,num1,m);
}
cout << num << " " << sum << " " << pdt; 

}