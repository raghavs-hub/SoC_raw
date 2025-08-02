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

int dfs(vvi& adjlist, vi& parents,vector<bool>& visited,int n,int start,vector<bool>& instack){
    //printf("starting dfs from %i\n",start);
    for(int x: adjlist[start]){
        if(instack[x] && x != start) {
            //printf("thecycle ends at %i and last second %i\n",x,start);
            parents[x] = start;
            return start;
        }
        else{
            parents[x] = start;
            visited[x] = true;
            instack[x] = true;
            int tmp = dfs(adjlist,parents,visited,n,x,instack);
            instack[x] = false;
            if(tmp != 0) return tmp;
        }
    }
    return 0;
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin >> n >> m;
vvi adjlist(n+1);

f(0,m,i){
    int a,b;
    cin >> a >> b;
    adjlist[a].PB(b);
}

vector<bool> visited(n+1,false);
vector<bool> instack(n+1,false);
vi parents(n+1);
vi cycle;
bool flag=false;
f(1,n+1,i){
    if(!visited[i] && adjlist[i].size() != 0){
        parents[i] = -1;
        visited[i] = true;
        instack[i] = true;
        int x = dfs(adjlist,parents,visited,n,i,instack);
        instack[i] = false;
        if(x != 0){
            int y=x;
            do{
                cycle.PB(y);
                y = parents[y];
            }while(y != x);
            cycle.PB(x);
            break;
        }
    }
}

if(cycle.size() == 0) cout << "IMPOSSIBLE" << nl;
else{
    cout << cycle.size() << nl;
    for(int g=cycle.size()-1;g>=0;g--){
        cout << cycle[g]<< " ";
    } cout << nl;
}

}