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


ll ways(vector<ll>& memo,ll n){
    if(n==0) return 0;
    else if(memo[n] != -1) return memo[n];
    else{
        memo[n] = (6*ways(memo,n-1)-7*ways(memo,n-2))%(1000000007);
        if(memo[n]<0) memo[n]+=1000000007;
        return memo[n];
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
vector<ll> memo(1e6+1,-1);
memo[1] = 2;
memo[2] = 8;
test{
    ll n; cin >> n;
    cout << ways(memo,n) << nl;
}

}