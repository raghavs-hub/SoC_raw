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

ll ways(int n,int target,int c[]){
    ll m = 1e9+7;
    //vector<vector<ll>> table(n+1, vector<ll>(target+1,0));
    vector<ll> curr(target+1,0),prev(target+1,0);
    curr[0] = prev[0] = 1;
    //f(0,n+1,i) table[i][0] = 1;
    f(1,n+1,y){
        f(1,target+1,x){
            curr[x] = prev[x];
            if(x>=c[y-1]) curr[x]+=curr[x-c[y-1]];
            curr[x] = curr[x]%m;
        }
        prev=curr;
    }
    return curr[target];
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,target;
cin >> n >> target;
int c[n];
f(0,n,i) cin >> c[i];

cout << ways(n,target,c) <<nl;
}