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


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n,m;
cin >> n >> m;

edge edges[m];

f(0,m,i){
    int a,b;
    ll c;
    cin >> a >> b >> c;
    edges[i] = {a,b,c};
}
//bool change=false;
int x=-1;
vll distances(n+1,1e13);
vi parent(n+1,-1);
for(int start=1; start<=n; ++start){
    if(distances[start]==1e13){
        distances[start]=0;
        f(1,n+1,j){
            x=-1;
            f(0,m,i){
                int ta = edges[i].a;
                int tb = edges[i].b;
                ll tc = edges[i].c;
                if(distances[ta]!= 1e13 && distances[tb] > distances[ta]+tc){
                    distances[tb] = distances[ta]+tc;
                    parent[tb] = ta;
                    x=tb;
                }
            }
            if(x==-1) break;
        }
        if(x != -1) break;
    }
}
if(x==-1) {cout << "NO";return 0;}
f(0,n,i) x= parent[x];

cout << "YES" << nl;
vi cycle;
int y = x;
do {
    cycle.push_back(y);
    y = parent[y];
} while (y != x);
cycle.push_back(x);

reverse(cycle.begin(),cycle.end());
for(auto x:cycle) cout << x << " ";
cout << nl;

}