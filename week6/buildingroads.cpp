#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef set<long long> sll;
typedef vector<long long> vll;


#define test int t;cin >> t;for(int z=0;z<t;z++)
#define getint(name) int name;cin >> name;
#define getll(name) long long name;cin >> name;
#define f(start,end,name) for(int name = (start);name < (end);name++)
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define nl '\n'
#define setIO(inputFile, outputFile) freopen(inputFile, 'r', stdin); freopen(outputFile, 'w', stdout)


void dfs(vector<vi>& adjlist,vector<bool>& visited,int src){
    if(visited[src]) return;
    visited[src] = true;
    for(auto x: adjlist[src+1]){
        if(visited[x-1]) continue;
        dfs(adjlist,visited,x-1);
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n;cin >> n;
vector<vi> adjlist(n+1);
int m; cin >> m;
f(0,m,i){
    int a,b;
    cin >> a >> b;
    adjlist[a].push_back(b);
    adjlist[b].push_back(a);
}
vi rds;
vector<bool> visited(n,false);
f(0,n,i){
    if(visited[i]) continue;
    else{
        rds.push_back(i+1);
        dfs(adjlist,visited,i);
    }
}
int x=rds.size()-1;
cout << x << nl;
f(1,x+1,j){
    cout << 1 << " " << rds[j] << nl;
}

}