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

ll funk(int x, int n, ll m,map<pii,ll>& hope,vector<ll>& v){
    if(x==n) return 1;
    else if(x==0 || x==1){
        ll num = factmm(v,2*n,m);
        ll den = ((factmm(v,n,m)*factmm(v,n,m))%m)*(n+1)%m;
        den = modinv(den,m);
        return num*den%m;
    } else if(hope.count({x,n}) != 0) return hope[{x,n}];
    else {
        hope[{x,n}] = (funk(x-1,n-1,m,hope,v) + funk(x+1,n,m,hope,v))%m;
        return hope[{x,n}];
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

ll n; cin >> n;
int m = 1e9+7;
int open = 0;
int close = 0;
cin.ignore(numeric_limits<streamsize>::max(), '\n');
string s;
getline(cin,s);
for(int k=0,n=s.length();k<n;k++){
    if(s[k]=='(') open++;
    else if(s[k] == ')') close++;
    if(close > open){
        cout << 0;
        return 0;
    }
}
if(n%2 != 0 || open > n/2){cout << 0;}
else{
    int x = open-close;
    n /= 2;
    n -= close;
    vector<ll> v(2*n+1,1);
    map<pii,ll> mymap;
    cout << funk(x,n,m,mymap,v);
}

}