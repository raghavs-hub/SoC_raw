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

ll maxpages(int n,ll x,ll prices[],ll pages[]){
    vector<ll> curr(x+1,0) ,prev(x+1,0);
    f(1,n+1,i){
        f(1,x+1,j){
            if(i==1) {if(j>=prices[i]) curr[j] = pages[i];else curr[j] = 0;}
            else if(j-prices[i]>=0){
                curr[j] = max(prev[j],prev[j-prices[i]]+pages[i]);
            } else{
                curr[j] = prev[j];
            }
            //printf("maks[%i][%i] : %i\n",i,j,maks[i][j]);
        }
        prev = curr;
    }
    return curr[x];
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

ll n,x;
cin >> n >> x;
ll price[n+1] = {0};
ll pages[n+1] = {0};

f(0,n,i) cin >> price[i+1];
f(0,n,i) cin >> pages[i+1];

cout << maxpages(n,x,price,pages) << nl;
}