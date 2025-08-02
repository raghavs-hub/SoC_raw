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


ll factmm(vector<ll>& v,int a, ll m){
    if(a == 0 | a == 1) return 1;
    else if(v[a] != 1) return v[a];
    else{
        v[a] = factmm(v,a-1,m)*a%m;
        return v[a];
    }
}

ll modinv(ll a, ll m){
    return a <= 1? a : m - ((__int128_t(m/a)*modinv(m%a,m))%m);
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

ll m=1e9+7;
ll n; cin >> n;
if(n%2 == 0){
n=n/2;
vector<ll> v(2*n+1,1);

ll num = factmm(v,2*n,m);
ll den = ((factmm(v,n,m)*factmm(v,n,m))%m)*(n+1)%m;
den = modinv(den,m);
cout << num*den%m;
} else cout << 0;
}