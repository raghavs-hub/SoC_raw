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

ll modpow(ll a,ll b,ll m){
    if(b==0) return 1;
    b = b%(m-1);
    ll u = modpow(a,b/2,m);
    u = u*u%m;
    if(b%2 == 1) u = ll(__int128_t(a)*u % m);
    return u;
}

ll modinv(ll a,ll m){
    return a <=1 ? a : m-(ll(m/a)*modinv(m%a,m)%m);
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

ll m = 1e9+7;
ll n; cin >> n;

ll tmp1 = n%2==0 ? n/2*n/2 : (n-1)*(n-1)/4+(n-1)/2+1;
ll tmp2 = n%2==0 ? 2*tmp1 : 2*tmp1-1;


ll sum = 0;
sum = (modpow(2,n*n,m)+2*modpow(2,tmp1,m)+modpow(2,tmp2,m))%m;
sum = (sum*modinv(4,m))%m;
cout << sum <<nl;

}