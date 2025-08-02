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

int negcycledfs(int ea,int eb,ll sum,vector<vector<pair<int,ll>>>& adjlist,vi& parent,int n,vector<bool>& visited){
    visited[eb] = true;
    for(auto x:adjlist[eb]){
        if(x.first == ea && sum+x.second<0){
            return eb;
        } else if(!visited[x.first]){
            visited[x.first]=true;
            parent[x.first]=eb;
            printf("parent of %i is %i\n",x.first,eb);
            int t = negcycledfs(ea,x.first,sum+x.second,adjlist,parent,n,visited);
            if(t != -1) return t;
        }
    }
    return -1;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin >> n >> m;

edge edges[m];
vector<vector<pair<int,ll>>> adjlist(n+1);


f(0,m,i){
    int a,b;
    ll c;
    cin >> a >> b >> c;
    edges[i] = {a,b,c};
    adjlist[a].PB({b,c});
}

bool change=false;
int ea,eb;
ll ec=0;
vll distances(n+1,1e14);
distances[1] = 0;
f(1,n+1,j){
    change=false;
    f(0,m,i){
        int ta = edges[i].a;
        int tb = edges[i].b;
        ll tc = edges[i].c;
        if(distances[ta]!= 1e14 && distances[tb] > distances[ta]+tc){
            distances[tb] = distances[ta]+tc;
            change=true;
            if(j==n && ec == 0)ea=ta,eb=tb,ec=tc;
        }
    }
}
vi parent(n+1,-1);
parent[eb] = ea;
parent[ea] = -1;
vector<bool> visited(n+1,false);
visited[ea] =  true;
vi the;

if(!change) cout << "NO" << endl;
else{
    printf("(%i, %i, %i)\n",ea,eb,ec);
    int end = negcycledfs(ea,eb,ec,adjlist,parent,n,visited);
    printf("end = %i\n",end);
    the.push_back(ea);
    while(parent[end] != -1){
        the.push_back(end);
        end = parent[end];
    }
    the.push_back(ea);
    cout << "YES" << nl;
    for(int x=the.size()-1;x>=0;x--){
        cout << the[x] << " ";
    } cout << nl;
}


}