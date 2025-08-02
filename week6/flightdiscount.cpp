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

ll djikstra(vector<pair<ll,int>> adj[],int n){
    multiset<vll> kindofq;
    vector<pair<ll,ll>> distances(n+1,{1e17,1e17});
    //vll maxs(n+1,-1e17);
    kindofq.insert({0,1,1});

    while(kindofq.size() != 0){
        vll tmp = *(kindofq.begin());
        kindofq.erase(kindofq.begin());
        ll cost=tmp[0];
        ll node=tmp[1];
        int cpn=tmp[2];

        if(cpn == 0 && distances[node].first<cost) continue;
        if(cpn == 1 && distances[node].second<cost) continue;

        for(auto child: adj[node]){
            int v=child.first,d=child.second;
        

        if(cpn==1){
            if(distances[v].second>cost+d){
                distances[v].second=cost+d;
                kindofq.insert({distances[v].second,v,1});
            }
            if(distances[v].first>cost+d/2){
                distances[v].first=cost+d/2;
                kindofq.insert({distances[v].first,v,0});
        }else{
            if(distances[v].first > cost+d){
                distances[v].first =cost+d;
                kindofq.insert({distances[v].first,v,0});
            }
        }
    }

    }
    
}return distances[n].first;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin >> n >> m;
vector<pair<ll,int>> adj[n+1];

f(0,m,i){
    int a,b;
    ll c;
    cin >> a >> b >>c;
    adj[a].push_back({b,c});
}

cout << djikstra(adj,n) << nl;

}