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



ll dicecomb(int n){
    ll m = 1e9+7;
    vector<ll> combs(n+1,0);
    combs[0] = 0;
    f(1,7,i){
        combs[i] = 1;
        f(1,i,j) combs[i]+=combs[j];    
    }
    if(n>=7){
        f(7,n+1,i){
            combs[i]=0;
            f(1,7,j) combs[i]+=combs[i-j];
            combs[i] = combs[i]%m;
        }
    }
    return combs[n];
}



int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n; cin >> n;

cout << dicecomb(n) << nl;


}