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

ll noofarrays(int n,int m, vi arr){
    vector<ll> curr(m+2,0),prev(m+2,0);
    if(arr[0]==0) f(1,m+1,k) prev[k]=1;
    else prev[arr[0]] = 1;
    curr=prev;
    f(2,n+1,i){
        if(arr[i-1]!=0){
            f(1,m+1,j) curr[j]=0;
            curr[arr[i-1]] = (prev[arr[i-1]-1]+prev[arr[i-1]]+prev[arr[i-1]+1])%1000000007;
        } else{
            f(1,m+1,j){
                curr[j]=(prev[j]+prev[j-1]+prev[j+1])%1000000007;
            }
        }
        prev=curr;
    }
    ll sum=0;
    f(1,m+1,j){
        sum=(sum+curr[j])%(1000000007);
    }
    return sum;
}






int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin >> n >> m;
vi v(n);
f(0,n,i) cin >> v[i];

cout << noofarrays(n,m,v) << nl;


}