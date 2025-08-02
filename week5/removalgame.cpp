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

ll maxscore(int l,int r,ll arr[],ll sum){
    if(l==r) return arr[l];
    else return max(sum-maxscore(l+1,r,arr,sum-arr[l]),sum-maxscore(l,r-1,arr,sum-arr[r]));
}

ll maxscore2(ll arr[],int n){
    vector<vector<ll>> table(n,vector<ll>(n,0));
    f(0,n,r){
        ll sum=table[r][r]=arr[r];
        for(int l=r-1;l>=0;l--){
            sum+=arr[l];
            table[r][l] = max(sum-table[r][l+1],sum-table[r-1][l]);
        }
    }
    return table[n-1][0];
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n;cin >> n;
ll arr[n];
f(0,n,i) cin >> arr[i];
cout << maxscore2(arr,n) << nl;
}