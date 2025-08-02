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


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

ll m = 10e8+7;
test{
    ll a,b;
    cin >> a >> b;
    cout << modpow(a,b,m) << nl;
}

}