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

ll inv(ll a, ll m){
    return a<=1 ? a : m - (ll(m/a)*inv(m%a,m))%m; 
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

ll mod = 998244353;
    map<int,int> toys;
    int n;
    cin >> n;
    int k[n];
    int sum=0;
    f(0,n,i){
        cin >> k[i];
        sum+=k[i];
        int p;
        f(0,k[i],j){
            cin >> p;
            toys[p]++;
        }
    }
    ll x,y = 1LL*((1LL*n*n) % mod)*sum % mod;
    for(auto c: toys){
        x += (1LL*c.second*c.second) % mod;
    }
    ll yinv = inv(y,mod);
    __int128_t res = __int128_t(x)*yinv % mod;
    cout << ll(res) << nl;



}