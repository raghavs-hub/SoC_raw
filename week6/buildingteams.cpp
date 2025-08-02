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


bool bipartitedfs(vi& team, vvi& adjlist,int n,int mypoint,int which_team){
    if(team[mypoint] != 0){
        if(team[mypoint] == which_team) return true;
        else return false;
    }
    team[mypoint] = which_team;
    for(auto x: adjlist[mypoint]){
        if(!bipartitedfs(team,adjlist,n,x,3-which_team)) return false;
    }
    return true;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin >> n >> m;

vvi adjlist(n+1);
int a,b;
f(0,m,i){
    cin >> a >> b;
    adjlist[a].PB(b);
    adjlist[b].PB(a);
}

vi team(n+1,0);
bool tmp=true;
f(1,n+1,i){
    if(team[i] == 0){
        if(!bipartitedfs(team,adjlist,n,i,1)){
            tmp=false;
            break;
        }
    }
}
if(tmp){
    f(1,n+1,i) cout << team[i] << " ";
    cout << nl;
} else{
    cout << "IMPOSSIBLE" << nl;
}
}