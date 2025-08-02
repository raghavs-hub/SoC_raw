#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define test int t;cin >> t;for(int z=0;z<t;z++)
#define f(start,end,name) for(int name = (start);name < (end);name++)
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define nl '\n'
#define setIO(inputFile, outputFile) freopen(inputFile, 'r', stdin); freopen(outputFile, 'w', stdout)


vector<ll> lcs(vector<ll> a, vector<ll> b,int n, int m){
    vector<vector<vector<ll>>> table(n+1,vector<vector<ll>>(m+1,vector<ll>(0)));
    f(1,n+1,x){
        f(1,m+1,y){
            int c = (a[x]==b[y])?1:0;
            int maxsize = max((table[x-1][y]).size(),(table[x][y-1]).size());
            if((table[x-1][y-1]).size()+c>=maxsize){
                table[x][y] = table[x-1][y-1];
                if(c) table[x][y].PB(a[x]);
            } else if(maxsize == (table[x-1][y]).size()){
                table[x][y] = table[x-1][y];
            } else table[x][y] = table[x][y-1];
        }
    }
    return table[n][m];
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
int n,m;
cin >> n >> m;
vector<ll> a(n+1),b(m+1);

f(0,n,i) cin >> a[i+1];
f(0,m,i) cin >> b[i+1];

vector<ll> v=lcs(a,b,n,m);
cout << v.size() << nl;
for(auto x:v){
    cout << x << " ";
} cout << nl;

}