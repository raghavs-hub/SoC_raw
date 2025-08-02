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

/*
int twoset(int n,int sum){
    if(sum==0) return 1;
    else if(sum<0) return 0;
    else if(n<=0) return 0;
    else return twoset(n-1,sum)+twoset(n-1,sum-n);
}

*/

ll modinv(ll a, ll m){
    return (a<=1)?a:m-(ll(m/a)*modinv(m%a,m));
}

int twoset(int n){
    if(n%4==1 || n%4==2) return 0;
    ll m = 1e9+7;
    ll sum = (n*(n+1))/4;
    vector<ll> prev(2*sum+1,0),curr(2*sum+1,0);
    curr[0] = prev[0] = 1;
    f(1,n+1,i){
        f(1,(i*(i+1))/2+1,l){
            if(l<i) curr[l] = prev[l];
            else curr[l] = (prev[l] + prev[l-i])%m;
        }
        prev=curr;
    }
    return (curr[sum]*modinv(2,m))%m;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;cin >> n;
cout << twoset(n) << nl;

}