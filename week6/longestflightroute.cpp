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

void dfs(int start,vi& succ,vector<bool>& visited,vi& dp,vi adj[]){
    visited[start] = true;
    for(auto x: adj[start]){
        if(!visited[x]) dfs(x,succ,visited,dp,adj);
        if(dp[x] != -1 && dp[start] < dp[x]+1){
            dp[start] = dp[x]+1;
            succ[start] = x;
    }
}
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin >> n >> m;
vi adj[n+1];
f(0,m,i){
    int a,b;
    cin >> a >>b;
    adj[a].PB(b);
}
vi dp(n+1,-1);
dp[n] =1;
vector<bool> visited(n+1,false);
vi successor(n+1,0);
dfs(1,successor,visited,dp,adj);
if(dp[1] == -1) cout << "IMPOSSIBLE" << nl;
else{
    cout << dp[1] << nl;
    int s=1;
    while(s != n){
        cout << s << " ";
        s=successor[s];
    }
    cout << n << nl;
}


}