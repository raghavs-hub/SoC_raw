#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef set<long long> sll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;


#define test int t;cin >> t;for(int z=0;z<t;z++)
#define getint(name) int name;cin >> name;
#define getll(name) long long name;cin >> name;
#define f(start,end,name) for(int name = (start);name < (end);name++)
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define nl '\n'
#define setIO(inputFile, outputFile) freopen(inputFile, 'r', stdin); freopen(outputFile, 'w', stdout)


void gr(int start, vi adj[], vll& dp, vector<bool>& visited){
    //cerr << "dfs started for node = " << start << nl;
    visited[start]=true;
    for(auto x:adj[start]){
        if(!visited[x]) gr(x,adj,dp,visited);
        //cerr << "dp of " << start << " changed from " << dp[start] << " to " << dp[start]+dp[x] << nl;
        dp[start]= (dp[start] +dp[x])%1000000007;
    }
    //cerr << "dfs ended for node = " << start << nl;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin >> n >> m;

vi adj[n+1];
vll dp(n+1,0);
vector<bool> visited(n+1,false);
dp[n] =1;

f(0,m,i){
    int a,b;
    cin >> a >> b;
    adj[a].PB(b);
}

gr(1,adj,dp,visited);
cout << dp[1] << nl;

}