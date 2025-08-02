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


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int m,n;
cin >> n >> m;

vi indeg(n+1,0);
vi adj[n+1];

f(0,m,i){
    int a,b;
    cin >> a >> b;
    adj[a].push_back(b),adj[b].push_back(a),indeg[b]++;
}

vi ans;
queue<int> q;

f(1,n+1,i) if(indeg[i]==0) q.push(i);

while(!q.empty()){
    
    auto x = q.front();
    q.pop();
    ans.push_back(x);

    for(auto y:adj[x]){
        indeg[y]--;
        if(indeg[y]==0) q.push(y);
    }
}

if(ans.size() == n) f(0,n,i) cout << ans[i]<< " ";
else cout << "IMPOSSIBLE";
cout << nl;

}