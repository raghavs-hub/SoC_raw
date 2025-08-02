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


vll djikstra(vector<vector<pair<int,ll>>>& adjlist,int k,int n){
    vi ans;
    multiset<pair<ll,int>> thes;
    vvll distance(n,vll(0));
    thes.insert({0,0});
    while(thes.size() != 0){
        auto it=thes.begin();
        ll d =it->first;
        int i = it->second;
        thes.erase(it);

        if(distance[i].size() >= k) continue;
        distance[i].PB(d);

        for(auto x:adjlist[i]){
                //distance[x.first].PB(d+x.second);
                thes.insert({d+x.second,x.first});
        }


    }
    return distance[n-1];
}


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m,k;
cin >> n >> m >> k;
vector<vector<pair<int,ll>>> adjlist(n);

f(0,m,i){
    int a,b;
    ll c;
    cin >> a >> b >> c;
    adjlist[a-1].PB({b-1,c});
}
vll ans = djikstra(adjlist,k,n);

f(0,k,i) cout << ans[i] << " ";

}