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

int mincoin(int target,int n, int coins[]){
    vi mins(target+1,target+1);
    mins[0]=0;
    f(1,target+1,k){
        f(0,n,i){
            if(k-coins[i]>=0) mins[k] = min(mins[k],mins[k-coins[i]]+1);
        }
    }
if(mins[target] == target+1) return -1;
else return mins[target];
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,target;
cin >> n >> target;
int coins[n];
f(0,n,i) cin >> coins[i];
cout << mincoin(target,n,coins) << nl;




}