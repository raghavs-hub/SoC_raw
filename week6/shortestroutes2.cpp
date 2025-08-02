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


int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int m,n,q;
cin >> n >> m >> q;
vvll distances(n,vll(n,1e14));

f(0,n,i) distances[i][i] = 0;

f(0,m,i){
    int a,b;ll c;
    cin >> a >> b >> c;
    distances[a-1][b-1] = min(c,distances[a-1][b-1]);
    distances[b-1][a-1] = distances[a-1][b-1];
}

f(0,n,i){
    f(0,n,j){
        f(0,n,k){
            distances[j][k] = min(distances[j][k],distances[j][i]+distances[i][k]);
            distances[k][j] = distances[j][k];
        }
    }
}

f(0,q,i){
    int a,b;
    cin >> a >> b;
    if(distances[a-1][b-1] >= 1e14) cout << -1 << nl;
    else cout << distances[a-1][b-1] << nl;
}

}