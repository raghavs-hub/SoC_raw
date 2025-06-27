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
    ll u = modpow(a,b/2,m);
    u = u*u%m;
    if(b%2 == 1) u = a*u % m;
    return u;
}

int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a,a);
}

ll modinv(ll a,ll m){
    return a <=1 ? a : m-(ll(m/a)*modinv(m%a,m)%m);
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);


ll m = 1e9+7;
int p,c;
cin >> p >> c;
ll sum = 0;

f(1,p+1,i){
    sum = (sum + modpow(ll(c),ll(gcd(i,p)),m))%m;
}

sum = (sum*modinv(p,m))%m;
cout << sum;

}