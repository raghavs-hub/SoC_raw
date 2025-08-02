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

void dijkstra(vector<pair<ll,int>> adj[],vll& price,vll& mi,vll& mx,vll& routes){
    multiset<pair<ll,int>> qe;
    price[1] =0;
    mi[1] = 0;
    mx[1] =0;
    routes[1] =1;
    qe.insert({0,1});

    while(!qe.empty()){
        auto [cost,node] = *(qe.begin());
        qe.erase(qe.begin());
        if(cost>price[node]) continue;
        for(auto child:adj[node]){
            int nd = child.first;
            ll c= child.second;
            if(price[nd] > price[node]+c){
                price[nd] = price[node]+c;
                routes[nd] = routes[node];
                mx[nd] = mx[node]+1;
                mi[nd] = mi[node]+1;
                qe.insert({price[nd],nd});
            } else if(price[nd] < price[node]+c){
                continue;
            }else{
                routes[nd] = (routes[nd]+routes[node])%(1000000007);
                mi[nd] = min(mi[nd],mi[node]+1);
                mx[nd] = max(mx[nd],mx[node]+1);
            }
        }        

    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int m,n;
cin >> n >> m;

vector<pair<ll,int>> adj[n+1];
vll price(n+1,1e17),mi(n+1,n+1),mx(n+1,0),routes(n+1,0);

f(0,m,i){
    int a,b;
    ll c;
    cin >> a >> b >> c;
    adj[a].PB({b,c});
}

dijkstra(adj,price,mi,mx,routes);

cout << price[n] << " " << routes[n] << " "  << mi[n] << " "  << mx[n] << nl; 
}