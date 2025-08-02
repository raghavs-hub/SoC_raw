#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef set<int> si;
typedef set<long long> sll;
typedef vector<long long> vll;


#define test int t;cin >> t;for(int z=0;z<t;z++)
#define getint(name) int name;cin >> name;
#define getll(name) long long name;cin >> name;
#define f(start,end,name) for(int name = (start);name < (end);name++)
#define PB push_back
#define ALL(x) (x).begin(), (x).end()
#define MP make_pair
#define nl '\n'
#define setIO(inputFile, outputFile) freopen(inputFile, 'r', stdin); freopen(outputFile, 'w', stdout)


string minpath(int n,vector<vector<char>> grid){
    
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);

int n; cin >> n;
vector<vector<char>> grid(n+1,vector<char>(n+1,'0'));
f(0,n,x) f(0,n,y) cin >> grid[x+1][y+1];
 
cout << minpath(n,grid)<<nl;

}