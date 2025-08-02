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

struct edge{
    int a,b;
    ll c;
};

bool dfs(int target,int s,vector<bool>& visited,vi adj[]){
    if(s==target) return true;
    else{
        //printf("trying to find %i from %i\n",target+1,s+1);
        visited[s] = true;
        for(auto x:adj[s]){
            if(!visited[x]) {if(dfs(target,x,visited,adj)) {return true;}}
        }
        return false;
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin >> n >> m;
vi adj[n];
edge thearr[m];
int a,b;
ll c;
f(0,m,i){
    cin >> a >> b >> c;
    adj[a-1].PB(b-1);
    thearr[i] = {a,b,-c};
}
bool change=false;

vll distances(n,1e14);
si ls;
distances[0] = 0;
int l;
f(0,n,j){
    change=false;
    f(0,m,i){
        int a1 = thearr[i].a;
        int b1 = thearr[i].b;
        int c1 = thearr[i].c; 
        if(distances[b1-1] > distances[a1-1]+c1){
            distances[b1-1] = distances[a1-1]+c1;
            change = true;
            if(j == n-1) ls.insert(b1-1);
        }
    }
}

if(change){
    for(auto l:ls){
        //cout << l << nl;
        vector<bool> visited(n,false);
        bool x = dfs(n-1,l,visited,adj);
        if(x){
        //cout << "x is true" << nl;
            vector<bool> tmpvisited(n);
            f(0,n,i) tmpvisited[i]=false;
            bool y = dfs(l,0,tmpvisited,adj);
            if(y) {cout << -1;return 0;}
        }
    }
}

cout << -distances[n-1];
cout << nl;


}