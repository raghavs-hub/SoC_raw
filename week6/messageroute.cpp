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


bool bfs(vvi& adjlist,vector<bool>& visited,vi& parent,int n){
    queue<int> theq;
    theq.push(1);
    int par=1;
    while(theq.size() != 0){
        if(theq.front() == n){
            return true;
        }
        par = theq.front();
        visited[par] = true;
        theq.pop();
        for(int x: adjlist[par]){
            if(!visited[x] && parent[x] == -1){
                parent[x] = par;
                //printf("parent of %i is %i\n",x,par);
                theq.push(x); 
            }
        }
    }
    return false;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

getint(n);
getint(m);
vvi adjlist(n+1);
int a,b;
f(0,m,i){
    cin >> a >> b;
    adjlist[a].PB(b);
    adjlist[b].PB(a);
}

vector<bool> visited(n+1,false);
vi parent(n+1,-1);

if(bfs(adjlist,visited,parent,n)){
    //for(auto x: parent) cout << x << " ";
    //cout << nl;
    vi tbp;
    int curr = n;
    while(curr != 1){
        tbp.PB(curr);
        //printf("parent of %i is %i\n",curr,parent[curr]);
        curr = parent[curr];
    }
    cout << tbp.size()+1 << nl;
    cout << 1 << " ";
    for(int i=tbp.size()-1;i>=0;i--) cout << tbp[i] << " ";
    cout << nl;
} else{
    cout << "IMPOSSIBLE" << nl;
}

}