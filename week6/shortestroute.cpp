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
edge thearr[m];
int a,b;
ll c;
f(0,m,i){
    cin >> a >> b >> c;
    thearr[i] = {a,b,c};
}
bool change=false;

vll distances(n,1e14);
distances[0] = 0;
f(0,n-1,i){
    change=false;
    f(0,m,i){
        int a1 = thearr[i].a;
        int b1 = thearr[i].b;
        int c1 = thearr[i].c;
        if(distances[b1-1] > distances[a1-1]+c1){
            change = true;
            distances[b1-1] = distances[a1-1]+c1;
        }
    }
    if(!change) break;
}

f(0,n,i) cout << distances[i] << " ";
cout << nl;

}