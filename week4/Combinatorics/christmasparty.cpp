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


ll derangementsmodm(vector<ll>& v,ll n, ll m){
    if(n == 1) return 0;
    else if(n == 2) return 1;
    else if(v[n] != 0) return v[n];
    else{
        v[n] = ((n-1)*(derangementsmodm(v,n-1,m)+derangementsmodm(v,n-2,m)))%m;
        return v[n];
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

ll m = 1e9+7;
vector<ll> derangements(1e6+1,0);
derangements[2] = 1;
ll n; cin >> n;
cout << derangementsmodm(derangements,n,m);
}